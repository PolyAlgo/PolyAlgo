Recherche optimale
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/recherche-optimale).
Contexte
------------------

Considérons une liste strictement croissante de longueur n d'entiers positifs inférieurs ou égaux à A.

Un jeu consiste à trouver la position x d'un nombre donné a appartenant à la liste. À chaque itération, on propose un nombre à l'indice m et on obtient l'un de trois réponses possibles: m < x, m = x ou m > x. On gagne si on connait x, autrement dit, on n'a pas besoin de proposer un nombre pour savoir qu'il est à la position x et ainsi gagner. Cependant, chaque itération coûte la valeur a du nombre proposé.

Considérant un tel jeu, la fonction Cost(l) permet calculer le pire coût de l'algorithme de recherche optimal pour une sous-liste composée des l premiers éléments le la liste donnée. La sous-liste contenant une seule ou aucune valeur a donc un pire coût nul, par exemple.

Le but du problème est de donner Cost(l) pour toutes les valeurs de l données en entrée.

#####Input Format

La longueur de la liste n et le nombre de cas à résoudre C sur la première ligne.

Ensuite, les n entiers de la liste sur une ligne, suivis de C lignes contenant un nombre l pour lequel il faut trouver Cost(l).

    0 <= n <= 300 

    0 <= l <= n 

    0 <= C <= 1000 

    0 <= A <= 2^30

#####Output Format

Sur chaque ligne, la valeur de Cost(l) associée au l du cas d'entrée correspondant.

#####Sample Input

    10 5 
    1 4 9 16 25 36 49 64 81 100 
    1 
    3 
    8 
    4 
    10

#####Sample Output

    0 
    4 
    74 
    10 
    130

#####Explanation

La suite contient 10 éléments et est arbitrairement constituée des carrés d'entiers strictement positifs. Il y a 5 cas à résoudre.

+ **Cas 1: l=1** : La liste est **[1]**. Le seul a pouvant être choisi est **1** et on sait qu'il se trouve à l'index **0**.

+ **Cas 2: l=3** : 
La liste est **[1, 4, 9]**. La solution optimale consiste à proposer **4** puisqu'aussitôt, on connait la réponse. Le coût est donc 4, puisqu'il s'agit du seul nombre proposé.

+ **Cas 3: l=8** : 
La liste est **[1, 4, 9, 16, 25, 36, 49, 64]**. La solution optimale consiste à choisir **25**, ce qui laisse les sous-listes **[1, 4, 9, 16] et [36, 49, 64]**. La seconde liste coûte **49**. Pour ce qui est de la première, on peut voir que la pire solution optimale pour cette sous-liste consiste à choisir **9** puis **1** si l'élément recherché a est **4**. Le pire coût arrive donc dans la situation où l'on cherche **36**, ou **64**, alors, avec l'algorithme de recherche optimal, on propose les entiers **[25, 49]**, qui ont pour somme **74**.

+ **Cas 4: l=4** : 
La liste **[1, 4, 9, 16]** a déjà été vue au cas précédent et dévoile les entiers **9** et **1** au pire cas de l'algorithme optimal. Cost(l) vaut donc **10**.

+ **Cas 5: l=10** : 
On prend toute la liste donnée au départ. Après avoir choisi **81** comme élément de départ, on obtient la sous-liste gratuite **[100]** et la sous-liste que nous connaissons déjà **[1, 4, 9, 16, 25, 36, 49, 64]**, qui coûte **74**. Cela donnerait donc un coût total de **155**. Cependant, il est possible d'obtenir mieux. 
On choisit au lieu **49** comme premier élément, retournant soit la liste **[64, 81, 100]**, qui coûte **81**, ou la liste **[1, 4, 9, 16, 25, 36]**, qui coûte **34**. Le pire cas serait alors de trouver a égal à **64** ou **100** et de devoir proposer les éléments **49** et **81** pour un coût total de **130**.
