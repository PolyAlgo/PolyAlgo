Force brute
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/force-brute).

Contexte
---
Un participant à la compétition décide de résoudre le problème de [recherche optimale](http://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/recherche-optimale) en utilisant la force brute. Pour ce faire, il veut recréer chaque arbre de recherche avec les éléments donnés, et prendre celui qui a le pire coût de recherche le moins élevé. Il faut donc qu'il ait une fonction qui lui permette d'évaluer le coût d'un arbre de recherche quelconque, le coût étant calculé comme au problème de recherche optimale.

Il se rend compte que cette méthode est inefficace, parce que le nombre d'arbres croit rapidement. Pour un arbre donné, vous devez calculer sont pire coût de recherche et le nombre d'arbres de recherche pour les mêmes éléments.

#####Input Format

Sur une ligne, l'arbre pour lequel il faut calculer les valeurs. Chaque noeud a le format (<sous-arbre gauche>.<valeur>.<sous-arbre droit>).

Ainsi, l'arbre suivant n'a qu'un seul noeud, la racine, qui a pour valeur 1: **(.1.)**. Un arbre ayant les valeurs [1, 2, 3], avec 2 comme racine et 1 et 3 comme noeuds fils gauche et droit, respectivement, sera noté: **((.1.).2.(.3.))**.

Le nombre d'éléments dans l'arbre peut aller jusqu'à 10^5 et leur valeur jusqu'à 10^15.

#####Output Format

Sur la première ligne, le pire coût de recherche dans l'arbre. Le pire coût est égal au maximum de la somme des valeur sur un chaîne reliant la racine à un sommet, incluant la racine et excluant le sommet.

Sur la seconde ligne, le nombre d'arbres de recherche binaires ayant le même nombre de noeuds que celui donné.

#####Sample Input

    (.1.(.2.(.3.)))

#####Sample Output

    3 
    5

#####Explanation

En partant de la racine, la chaîne la plus coûteuse jusqu'à un noeud est celle qui se rend à **3**. Les valeurs sur cette chaîne sont : **[1, 2, 3]**. Comme on exclue le dernier noeud du coût, la somme, et par conséquent la valeur calculée du pire coût est **1+2=3**.

Les 5 arbres ayant 3 noeuds sont les suivants: 
    (.1.(.2.(.3.))) 
    
    (.1.((.2.).3.)) 
    
    ((.1.).2.(.3.)) 
    
    ((.1.(.2.)).3.) 
    
    (((.1.).2.).3.)
