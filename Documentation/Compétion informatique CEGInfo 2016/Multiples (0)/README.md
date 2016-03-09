Multiples
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/multiples).
Contexte
------------------

On donne un nombre premier p ainsi qu'une liste M de nombres qui sont des multiples de p. Le but est de trouver pour chaque m de M, les premiers chiffres (ceux de plus faible rang) du quotient m/p. Cependant, par souci de généralité, on doit trouver les premiers chiffres peu importe la base b demandée. S'il y a moins de chiffres dans le quotient que n, alors on comble le vide avec des 0.

#####Input Format

Sur la première ligne, on a le nombre premier p, la base b, le nombre de chiffres désirés n et le nombre de multiples k, séparés par des espaces. Le nombre p est donné dans la base b et le reste de ces nombres sont donnés en base 10.

Sur les k lignes suivantes, on a les multiples m, à raison de un par ligne, donnés dans la base b. Pour exprimer les chiffres supérieurs à 10 dans les bases supérieures à 10, on emploie des parenthèses et on y écrit chaque chiffre transformé dans la base 10. Ainsi, par exemple, 123 en base 16 serait noté **7(11)**, 11 en base 12 serait noté **(11)** et 12 en base 12 serait noté **10**.

#####Output Format

Sur chaque ligne, la partie du quotient trouvée correspondant à un des multiples, exprimé dans la base demandée, avec le nombre de chiffres demandé.

#####Sample Input

111 2 5 3 
1110 
1111001100001 
1101111001

#####Sample Output

00010 
10111 
11111

#####Explanation

Le nombre premier est **111** soit **7** en base 10. Nous allons expliquer le raisonnement pour chacun des multiples.

- **1110 = 14** : 14/7 vaut 2, donc les 5 premiers chiffres en base 2 sont **00010**.

- **1111001100001 = 7777** : 7777/7 vaut 1111, soit 10001010111 en base 2. Les 5 premiers chiffres (de plus faible rang) sont donc **10111**.

- **1101111001 = 889** : 889/7 vaut 127, soit 1111111 en base 2. Les 5 premiers chiffres de plus faible rang sont donc **11111**.
