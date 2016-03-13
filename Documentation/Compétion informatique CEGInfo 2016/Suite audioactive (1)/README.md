Suite audioactive
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/suite-audioactive).
Contexte
------------------

Le problème consiste à trouver le premier terme d'une suite de Conway (soit Look-and-say sequence en anglais). Il s'agit d'une séquence où chaque terme est la lecture du précédent en disant combien de fois chaque chiffre est répété. Par exemple, 1 est suivi de 11 car c'est le chiffre 1 une seule fois. 222 serait suivi de 32, car il y a 3 occurences du chiffre 2 de suite. 2233 serait suivi de 2223, car il y a 2 occurences du chiffre 2 puis 2 occurences du chiffre 3. N'importe quel nombre peut commencer une telle suite, mais seulement une partie peuvent être successeurs. Aucun des termes ne contient de zéros.

Il faut trouver, s'il existe, le premier terme d'une suite contenant un nombre donné, c'est à dire le nombre de la suite qui ne peut pas être le successeur d'aucun autre nombre.

#####Input Format

Un terme T de la suite, soit n'importe quel entier positif ne contenant pas de zéros.

0 < T < 10^(10^6)

#####Output Format

Le premier terme de la suite ou ':(' s'il n'y en a pas.

#####Sample Input

    312331

#####Sample Output

    11133111

#####Explanation

**312331** suit **11133111** qui n'a pas de prédécesseur: 
- La partie **1113** deviendrait **13**, ce qui fonctionne. 
- La partie **3111** décrit 3 fois 1 et 1 fois 1 ce qui donnerait **1111**, qui est cependant le prédécesseur de **41** et non pas de **3111**, ainsi, c'est un terme qui n'a pas de prédécesseur. C'est donc le premier terme de cette instance de la suite.
