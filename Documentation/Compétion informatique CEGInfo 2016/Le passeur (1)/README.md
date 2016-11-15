Le passeur  
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/le-passeur).
Contexte
------------------

Un vieux passeur vivant près d'une rivière éloignée s'est converti en consultant en logistique de passage de rivière lorsque des passeurs plus jeunes sont arrivés dans son village grandissant. Bien qu'il aime son nouvel emploi, il est souvent approché par des gens qui lui proposent des énigmes qu'il trouve moqueuses. Ce sont de simples problèmes de passage de rivière qu'il souhaite régler une fois pour toute.

Passage de rivière
------------------
Les [problèmes de passages de rivière](https://fr.wikipedia.org/wiki/Probl%C3%A8mes_de_passage_de_rivi%C3%A8re) ([en](https://en.wikipedia.org/wiki/River_crossing_puzzle)) consistent à devoir faire passer un nombre d'individus d'une rive à l'autre de la rivière avec un nombre limité de places sur un bateau. À cela s'ajoutent des contraintes formulées de la façon suivante: une paire d'individus donnée ne peut pas être mise ensemble sans qu'un troisième individu donné ne soit présent.

Le bateau est sur la rive de départ pour commencer et fait ensuite des trajets en alternant de sens jusqu'à la fin, lorsqu'il finit sur la rive d'arrivée (opposée à celle de départ) avec tous les individus. Il n'est pas nécessairement plein pour chaque trajet. Cependant, il doit toujours y avoir quelqu'un à bord du bateau.

Problème
------------------
Vous devez aider le consultant en faisant un programme qui va résoudre n'importe quel problème de passage de rivière de la forme décrite ci-haut.

Exemples
------------------
Un problème de traversée souvent posé à l'ancien passeur est celui du loup, de la chèvre et du chou. Dans ce problème, un fermier doit traverser à bord d'un bateau à deux place un rivière en emmenant son loup, sa chèvre et un chou. Le fermier et chacune de ses choses prennent une place chacuns à bord du bateau. Si le loup et la chèvre sont présents sans le fermier (que ce soit sur une rive ou à bord), alors le loup mangera la chèvre et il en est de même pour la chèvre et le chou.

Un autre problème déjà rencontré est celui des dompteurs et de leurs singes. Trois dompteurs sont chacun accompagés d'un singe de leur cirque. Les six individus doivent traverser la rivière à bord d'un radeau à deux places. Si un singe n'est pas surveillé par son dompteur, alors il sera tenté d'attaquer n'importe quel autre dompteur présent.

Évidemment, dans ces deux problèmes, tous les individus doivent traverser la rivière sains et saufs. (Note: Par simplicité, tous les individus peuvent conduire le bateau dans notre scénario général. Cela fait que le chou pourrait faire un mouvement à bord du bateau à lui seul.)

#####Input Format

Le nombre d'individus voulant traverser N et le nombre de places maximal B dans le bateau sur la première ligne, séparés par un espace.

Sur les autres lignes, les contraintes. Chaque contrainte est une liste de trois identifiants séparés par des espaces. Les individus correspondant au deux premiers identifiants ne peuvent pas être ensembles à moins que le troisième ne soit présent aussi. Pour simplifier, les identifiants des individus sont des entiers entre 1 et le nombre d'invividus N.

#####Output Format

Le minimum du nombre de traversées nécessaires à faire passer tous les individus de l'autre côté.

Si aucune solution n'est possible, mettre ':(' en sortie.

#####Sample Input

    2 
    1 5 4 
    1 6 4 
    2 4 5 
    2 6 5 
    3 4 6 
    3 5 6

#####Sample Output

    11

#####Explanation

Ce problème correspond à celui des singes et des dompteurs, avec les singes étant les individus 1, 2 et 3 et les dompteurs 4, 5 et 6. Le singe x appartient au dompteur x+3.

Il est possible de faire les traversées suivantes:

(Aller: A, Retour: R) + identifiants des individus à bord

    A: 1 2 
    R: 2
    
    A: 2 3 
    R: 3
    
    A: 4 5 
    R: 2 5
    
    A: 5 6 
    R: 1
    
    A: 1 2 
    R: 2
    
    A: 2 3

Cela fait un total de 11 mouvements de bateau, ce qui est le minimum pour ce problème.