  %r�cup�re le plateau de jeu
:- use_module(case).



%------------------------------------------------------------------------------------------------
%               ******* JEU RASENDE ROBOTER *******
% trouve le chemin le plus court entre un robot et une cible...
% si elle est atteignable sans d�placer d'autres robots
%------------------------------------------------------------------------------------------------
jeu_1robot(XRBleu,YRBleu, XRVert,YRVert, XRRouge,YRRouge, XRJaune,YRJaune, RObj, XCible,YCible, Chemin, NbCoups) :-
                       % enregistre la position des quatres robots en var. globales
                       nb_linkval(rbtBleu,[XRBleu,YRBleu]),
                       nb_linkval(rbtVert,[XRVert,YRVert]),
                       nb_linkval(rbtRouge,[XRRouge,YRRouge]),
                       nb_linkval(rbtJaune,[XRJaune,YRJaune]),
                       %on r�cup�re la position du robot qui doit atteindre la cible
                       nb_getval(RObj,PosRobot),
                       % Initialise l'openList et ajoute le noeud de d�part
                       nb_linkval(openList,[[PosRobot,PosRobot,0,0,0]]),
                       % Initialise la closedList comme liste vide
                       nb_linkval(closedList,[]),
                       % Sauvegarde la position de d�part et celle d'arriv�e
                       nb_linkval(start,PosRobot),
                       nb_linkval(cible,[XCible,YCible]),
                       a_star( RObj, [XCible,YCible], Chemin ),
                       nb_coups(NbCoups).

%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------



%------------------------------------------------------------------------------------------------
%******* ALGORITHME A* *******
%------------------------------------------------------------------------------------------------
%a_star( +nomRobot, +PositionFinaleSouhait�e, -CheminPourYArriver)
%les variables globales doivent �tre pr�alablement initialis�es

a_star( Robot, PositionFinale, Chemin ) :-  buildPath(Robot, PositionFinale),
                                            %Parcourt la closedList et renvoie le chemin trouv�
                                            retourneChemin(L),
                                            %Formalise cette liste pour �tre manipulable par l'interface graphique en Java
                                            listeSortie(L,S),
                                            concat_atom(S,'|',Chemin).
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------

 
%------------------------------------------------------------------------------------------------
% builPath analyse les noeuds contenus dans OpenList et les transf�re dans closedList
% selon la m�thode de l'algorithme A*
%------------------------------------------------------------------------------------------------
buildPath(Robot, PosFinale) :- getBestNodeFromOpenList([PosFinale,_,_,_,_]),
                               extractBestNodeFromOpenList([Pos,_,_,_,_]),
                               nb_linkval(Robot,Pos), !.
                               
buildPath(Robot, PosFinale) :- extractBestNodeFromOpenList([Pos,_,_,_,_]),
                               nb_linkval(Robot,Pos),
                               insertNextPositionsInOpenList(Pos),
                               buildPath(Robot, PosFinale).
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------




%------------------------------------------------------------------------------------------------------------------------------------------------------
%extractBestNodeFromOpenList( -Node ).
%l'enl�ve d'openList et le met dans closedList
%------------------------------------------------------------------------------------------------------------------------------------------------------
extractBestNodeFromOpenList(Node) :-
        getBestNodeFromOpenList(Node),
        nb_getval(openList,OL), retirerNoeud(Node,OL,NewOL), nb_setval(openList,NewOL),
        nb_getval(closedList,CL), ajouterNoeud(Node,CL,NewCL), nb_setval(closedList,NewCL).
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------


%------------------------------------------------------------------------------------------------------------------------------------------------------
%getBestNodeFromOpenList( -Node ).
%Renvoie le meilleur noeud de l'openList
%------------------------------------------------------------------------------------------------------------------------------------------------------
getBestNodeFromOpenList(Node) :- nb_getval(openList,L), getBest(L,Node).
getBest([Node],Node) :- !.
getBest([[P1,PP1,H1,G1,F1]|R],[P1,PP1,H1,G1,F1]) :- getBest(R,[_,_,_,_,F2]), F1 =< F2, !.
getBest([[_,_,_,_,F1]|R],[P2,PP2,H2,G2,F2]) :- getBest(R,[P2,PP2,H2,G2,F2]), F1 > F2.
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------






%------------------------------------------------------------------------------------------------------------------------------------------------------
%insertNextPositionsInOpenList( +PosParent).
%
%Ins�re dans openList les noeuds repr�sentant les positions atteignables depuis la position pass�e en param�tre
%N'ins�re que les noeuds n'�tant pas encore pr�sents ou ceux ayant une valeur F inf�rieure � l'un des noeuds d�j� pr�sent
%------------------------------------------------------------------------------------------------------------------------------------------------------

insertNextPositionsInOpenList(PosParent) :-
           getAllAccessiblePositions(PosParent,ListPositions),
           insertNextPositionsInOpenList(PosParent,ListPositions).
           
insertNextPositionsInOpenList(_,[]) :- !.

%si le nouveau noeud n'est pas encore dans openList ni closedList, on l'ajoute
insertNextPositionsInOpenList(PosParent,[Pos|R]) :-
          creerNoeud(Pos,PosParent,Noeud), nb_getval(openList,OL), nb_getval(closedList,CL),
          not(member([Pos,_,_,_,_],OL)), not(member([Pos,_,_,_,_],CL)), nb_linkval(openList,[Noeud|OL]),
          insertNextPositionsInOpenList(PosParent,R),!.

%si le nouveau noeud n'est pas encore dans openList mais est dans closedList, on NE l'ajoute PAS
insertNextPositionsInOpenList(PosParent,[Pos|R]) :-
          creerNoeud(Pos,PosParent,_), nb_getval(openList,OL), nb_getval(closedList,CL),
          not(member([Pos,_,_,_,_],OL)), member([Pos,_,_,_,_],CL),
          insertNextPositionsInOpenList(PosParent,R),!.
                                                    
%si le nouveau noeud est d�j� dans openList, on l'ajoute si son F est inf�rieur au F du noeud d�j� pr�sent
insertNextPositionsInOpenList(PosParent,[Pos|R]) :-
          creerNoeud(Pos,PosParent,[Pos,PosParent,H,G,F]), nb_getval(openList,L),
          member([Pos,PosParent2,H2,G2,F2],L), F < F2 , retirerNoeud([Pos,PosParent2,H2,G2,F2],L,L2),
          nb_linkval(openList,[[Pos,PosParent,H,G,F]|L2]), insertNextPositionsInOpenList(PosParent,R),!.

%si le nouveau noeud est d�j� dans openList, on ne l'ajoute pas si son F est sup�rieur au F du noeud d�j� pr�sent
insertNextPositionsInOpenList(PosParent,[Pos|R]) :-
          creerNoeud(Pos,PosParent,[Pos,PosParent,_,_,F]), nb_getval(openList,L),
          member([Pos,_,_,_,F2],L), F >= F2,
          insertNextPositionsInOpenList(PosParent,R).
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------




%------------------------------------------------------------------------------------------------------------------------------------------------------
%retirerNoeud( +Noeud, +ListeDesNoeuds, -NouvelleListeSansNoeud)
retirerNoeud(Noeud,[Noeud|R],R) :- !.
retirerNoeud(Noeud1,[Noeud2|R],[Noeud2|L]) :- dif(Noeud1,Noeud2), retirerNoeud(Noeud1,R,L).

%ajouterNoeud(+Noeud, +ListeDesNoeuds, -NouvelleListeAvecNoeud)
ajouterNoeud(Noeud,Liste,[Noeud|Liste]).
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------



%------------------------------------------------------------------------------------------------------------------------------------------------------
%creerNoeud(+Pos, +PosParent, -[Pos, PosParent, h(Pos), g(Pos), f(Pos)]).
%Cr�e un "noeud" qui sera manipul� dans l'open et closedList. De la forme: [Position,PositionParent,Heuristique,Co�t(ici=Nb de coups),Heur+Co�t]
%------------------------------------------------------------------------------------------------------------------------------------------------------
%Pour une position donn�e et sa positionParent, on cr�e un nouveau noeud � ajouter dans openList
creerNoeud([X,Y],[XP,YP],[[X,Y],[XP,YP],H,G,F]) :- nb_getval(cible,PosFinale), getHeuristicValue([X,Y],PosFinale,H), getParentsCost([XP,YP],C), G is C+1, F is G+H.

%getHeuristicValue( +PositionDepart, +PositionFinale, -V ).  Donne la distance euclidienne entre les 2 positions...
getHeuristicValue([XStart,YStart], [XFinal,YFinal], V) :- X1 is abs(XFinal-XStart), Y1 is abs(YFinal-YStart), V is sqrt((X1*X1)+(Y1*Y1)).

%getParentsCost
getParentsCost([X,Y],C) :- nb_getval(closedList,L), member([[X,Y],_,_,C,_],L),!.
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------



%------------------------------------------------------------------------------------------------------------------------------------------------------
%getAllAccessiblePositions( +Position, -AccessiblePositionsList ).
%renvoie la liste de toutes les positions atteignables depuis Position
getAllAccessiblePositions([X,Y],[[XH,YH],[XB,YB],[XG,YG],[XD,YD]]) :-
                       gauche(X,Y,XG,YG), droite(X,Y,XD,YD),
                       haut(X,Y,XH,YH), bas(X,Y,XB,YB).
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------





%------------------------------------------------------------------------------------------------
%*****************************************************
%******** Fonctions de d�placement des robots ********
%*****************************************************
%------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------
%******* DEPLACEMENT VERS LA GAUCHE *******
%------------------------------------------------------------------------------------------------
%dans le cas o� la case courante contient un mur � gauche, la position reste inchang�e
gauche(X,Y,X,Y) :- case(X,Y,_,_,1,_),!.

%dans le cas o� la case voisine de gauche contient un robot, la position reste inchang�e
gauche(X,Y,X,Y) :- X0 is X-1, nb_getval(rbtBleu,[X0,Y]),!.
gauche(X,Y,X,Y) :- X0 is X-1, nb_getval(rbtVert,[X0,Y]),!.
gauche(X,Y,X,Y) :- X0 is X-1, nb_getval(rbtJaune,[X0,Y]),!.
gauche(X,Y,X,Y) :- X0 is X-1, nb_getval(rbtRouge,[X0,Y]),!.


%sinon, on fait un appel r�cursif du pr�dicat gauche en se d�placement d'une case vers la gauche
gauche(X,Y,X2,Y) :- X1 is X-1, gauche(X1,Y,X2,Y).


%------------------------------------------------------------------------------------------------
%******* DEPLACEMENT VERS LA DROITE *******
%------------------------------------------------------------------------------------------------
%se d�placer vers la droite
%dans le cas o� la case courante contient un mur � droite, la position reste inchang�e
droite(X,Y,X,Y) :- case(X,Y,_,_,_,1),!.

%dans le cas o� la case voisine de droite contient un robot, la position reste inchang�e
droite(X,Y,X,Y) :- X0 is X+1, nb_getval(rbtVert,[X0,Y]),!.
droite(X,Y,X,Y) :- X0 is X+1, nb_getval(rbtJaune,[X0,Y]),!.
droite(X,Y,X,Y) :- X0 is X+1, nb_getval(rbtBleu,[X0,Y]),!.
droite(X,Y,X,Y) :- X0 is X+1, nb_getval(rbtRouge,[X0,Y]),!.

%sinon, on fait un appel r�cursif du pr�dicat droite en se d�placement d'une case vers la droite
droite(X,Y,X2,Y) :- X1 is X+1, droite(X1,Y,X2,Y).


%------------------------------------------------------------------------------------------------
%******* DEPLACEMENT VERS LE HAUT *******
%------------------------------------------------------------------------------------------------
%se d�placer vers le haut
%dans le cas o� la case courante contient un mur en haut, la position reste inchang�e
haut(X,Y,X,Y) :- case(X,Y,1,_,_,_),!.

%dans le cas o� la case voisine du haut contient un robot, la position reste inchang�e
haut(X,Y,X,Y) :- Y0 is Y+1, nb_getval(rbtJaune,[X,Y0]),!.
haut(X,Y,X,Y) :- Y0 is Y+1, nb_getval(rbtVert,[X,Y0]),!.
haut(X,Y,X,Y) :- Y0 is Y+1, nb_getval(rbtRouge,[X,Y0]),!.
haut(X,Y,X,Y) :- Y0 is Y+1, nb_getval(rbtBleu,[X,Y0]),!.

%sinon, on fait un appel r�cursif du pr�dicat haut en se d�placement d'une case vers le haut
haut(X,Y,X,Y2) :- Y1 is Y+1, haut(X,Y1,X,Y2).


%------------------------------------------------------------------------------------------------
%******* DEPLACEMENT VERS LE BAS *******
%------------------------------------------------------------------------------------------------
%se d�placer vers le bas
%dans le cas o� la case courante contient un mur en bas, la position reste inchang�e
bas(X,Y,X,Y) :- case(X,Y,_,1,_,_),!.

%dans le cas o� la case voisine du bas contient un robot, la position reste inchang�e
bas(X,Y,X,Y) :- Y0 is Y-1, nb_getval(rbtVert,[X,Y0]),!.
bas(X,Y,X,Y) :- Y0 is Y-1, nb_getval(rbtJaune,[X,Y0]),!.
bas(X,Y,X,Y) :- Y0 is Y-1, nb_getval(rbtRouge,[X,Y0]),!.
bas(X,Y,X,Y) :- Y0 is Y-1, nb_getval(rbtBleu,[X,Y0]),!.

%sinon, on fait un appel r�cursif du pr�dicat bas en se d�placement d'une case vers le bas
bas(X,Y,X,Y2) :- Y1 is Y-1, bas(X,Y1,X,Y2).

%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------





%------------------------------------------------------------------------------------------------
%********************* fonctions diverses ***********************
%******* AFFICHAGE DE OPENLIST ET CLOSEDLIST ET DU CHEMIN *******
%------------------------------------------------------------------------------------------------
affOpenList :- nb_getval(openList,L), affOpenList(L).
affOpenList([]) :- writeln(''),!.
affOpenList([T|R]) :- writeln(T), affOpenList(R).

%---------------------------------------------------------------------------------------------------------------------------
affClosedList :- nb_getval(closedList,L), affClosedList(L).
affClosedList([]) :- writeln(''),!.
affClosedList([T|R]) :- writeln(T), affClosedList(R).

%---------------------------------------------------------------------------------------------------------------------------
affLists :- writeln('***** OPENLIST ******'), affOpenList, writeln('***** CLOSEDLIST ******'), affClosedList.

%---------------------------------------------------------------------------------------------------------------------------
affChemin :- nb_getval(closedList, [[A,B,C,NbCoups,D]|R]), write('Chemin trouv� en '), write(NbCoups), writeln(' coups'),
             nb_getval(cible,Cible), nb_getval(start,Start), affChemin(Start,Cible,[[A,B,C,NbCoups,D]|R]).

affChemin(Start, _, [[Start,Start,0,0,0]|_]) :- write(Start),write(' <-- '),!.
affChemin(Start, Cible, [[Cible,Parent,_,_,_]|R]) :- write(Cible),write(' <-- '), affChemin(Start, Parent, R),!.
affChemin(Start, Cible, [_|R]) :- affChemin(Start, Cible, R).


%---------------------------------------------------------------------------------------------------------------------------
retourneChemin(ListeRev) :- nb_getval(closedList, [[A,B,C,NbCoups,D]|R]),
                  nb_getval(cible,Cible), nb_getval(start,Start), retourneChemin(Start,Cible,[[A,B,C,NbCoups,D]|R],Liste), rev(Liste,ListeRev).

retourneChemin(Start, _, [[Start,Start,0,0,0]|_],[Start]) :- !.
retourneChemin(Start, Cible, [[Cible,Parent,_,_,_]|R],[Cible|Suite]) :- retourneChemin(Start, Parent, R, Suite),!.
retourneChemin(Start, Cible, [_|R], L) :- retourneChemin(Start, Cible, R, L).

%nbCoups()
nb_coups(Nb) :- nb_getval(closedList, [[_,_,_,Nb,_]|_]).

%---------------------------------------------------------------------------------------------------------------------------
%Inverse les �l�ments de la liste L1
rev(L1, L2):- rev(L1, [], L2).
rev([], Acc,Acc).
rev([X|Rest], Acc,Result):- rev(Rest, [X|Acc], Result).

%-----------------------------------------------------------------------------------
%Mise en forme de la liste des coordonn�es renvoy�es
listeSortie([],[]).
listeSortie([L|R],[S|R2]):- concat_atom(L,',',S),listeSortie(R,R2).