Trop long trop cher  
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/trop-long-trop-cher-1).

Contexte
------------------
Polytron Ltée, une compagnie de télécommunication québécoise, dispose d'un large réseau de télécommunication rejoignant les régions les plus éloignées de la province. Bâti essentiellement à l'aide de câbles en cuivre, Polytron désire désormais le remplacer par un réseau à fibres optiques de manière à demeurer compétitif face à son plus grand concurrent, Bets Inc.

Toutefois, après avoir consulté maints ingénieurs, il apparaît que le projet n'est pas aussi abordable que prévu. En effet, une partie significative du réseau de Polytron provient de concurrents ayant été acquis au fil des années. Ainsi, par certains endroits, le réseau est fortement redondant; plusieurs chemins sont possibles entre deux mêmes endroits. Considérant le coût élevé relié à l'installation d'un câble de fibre optique, Polytron vous demande d'élaborer un programme permettant d'indiquer la quantité minimale de fibre optique à installer de manière à rejoindre un ensemble de lieux finis et ce, en limitant l'installation des nouveaux câbles aux chemins empruntés précédemment (ex: si auparavant A n'était pas directement connecté à B par le biais d'un câble en cuivre, il ne pourra pas plus l'être par un câble de fibre optique).

#####Input Format

La première ligne contient le nombre n de lieux connectés par le biais de câble en cuivre que l'on désire remplacer.

Pour chaque lieu, on compte ensuite une ligne comportant n valeurs. Deux types de valeurs sont possibles:

+ Un entier positif
+ -

Considérons la ième valeur d'une ligne quelconque. Une valeur numérique indique la distance entre ce lieu et le lieu représenté par la (i + 1)ème ligne. Un tiret quant à lui indique qu'il n'y aucune connexion.

#####Output Format

Chaque paire de lieu qui devront être connecté avec de la fibre optique. Ces paires doivent être, à l'interne, ordonnées en ordre croissant (l'indice représentant le lieu du premier élément de la paire doit être inférieur à celui du second élément de la paire). Aussi, elles doivent être ordonnée en ordre croissant entre elles (le premier élément de la première paire doit être supérieur au premier élément de la seconde paire; si les deux premiers éléments sont égaux, la même règle doit s'appliquer aux seconds éléments).

#####Exemple:

    1 4
    2 3
    2 6
    4 5
    4 6
    6 8
 
#####Sample Input

    3  
    - 3 1
    3 - 2
    1 2 -

#####Sample Output

    1 3
    2 3
#####Explanation

La situation décrite par le fichier d'entrée dénote un triangle. Ainsi, seuls deux liens de fibre optiques sont nécéssaires si l'on désire inclure l'ensemble des lieux dans le réseau. Considérant les trois distances suivantes:

+ 1 (du lieu 1 à 3)
+ 2 (du lieu 2 à 3)
+ 3 (du lieu 1 à 2)

L'installation de fibre optique entre les lieux 1 et 3 et entre les lieux 2 et 3 est la solution qui minimise au maximum la quantité de fibre nécessaire.