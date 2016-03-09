PolyPlacement 
==================
Tel que présenté sur HackerRank lors de la compétition informatique CEGInfo 2016 à l'école Polytechnique de Montréal [(lien)](https://www.hackerrank.com/contests/competition-informatique-ceginfo-cegl-2016/challenges/polyplacement).
Contexte
------------------

PolyPlacement est une nouvelle firme de courtage et à besoin de votre aide afin d'analyser les options offerte à leurs clients. Le mandat qui vous est confié consiste à aider la firme de courtage à prédire le montant final d'un investissement. Bien entendu chaque investisseur étant différent, votre application devra prendre en compte le profil du client.

Dans le cas de PolyPlacement, tous les clients sont représentés comme étant soit des investisseurs "sécuritaires" ou "très téméraires". Afin de vous aider à comprendre, voici une légère description des investisseurs.

Un investisseur dit sécuritaire est un individu qui va préférer obtenir un maximum de profit pour un risque minimal. L'application devra donc déterminer, pour les clients de ce profil, avec quel montant d'argent le client doit-il s'attendre à la fin de l’année.

Un investisseur dit très téméraire est un individu qui ne prend pas le risque en considération et qui est prêt à tout miser afin d'avoir la chance d'obtenir le montant maximal. Pour ce genre de client, l'application doit déterminer quel serait le montant maximal que le client peut atteindre.

Il est important de noter que PolyPlacement ne permet pas la détention de plusieurs placements de façons simultanés. Les ventes auront toujours lieu le matin à l'ouverture de la bourse alors que l'achat s'effectue tout juste avant la fermeture de la bourse.

#####Input Format

La première ligne contient le nombre de simulation qui doit être calculé. Compris entre [1,190]

Pour chaque simulation, une première ligne **n** indique le nombre de placement qui devront être considéré (compris entre [1,320]). La seconde ligne indique le type du client (0 pour "sécuritaire" et 1 pour "très téméraire") La troisème ligne indique la duré de la simulation en jours **j**. Les **n** lignes suivante sont composé comme suis: **a b c d c d c d**. Le nombre de fois que la séquence **c d** ce répète est compris entre [1,10].

#####Définition:

j => Nombres de jours de la simulation [30,95]

a => Jours ou l'achat doit être effectué. Compris entre [0,j-1]

b => Jours ou la vente sera effectué. Compris entre [a+1,j]

c => Un nombre compris entre [0,1] qui indique les chances d'obtenir le montant d'argent annoncé par la lettre **d** qui suit.

d => Montant d'argent que le placement rapportera compris entre[-1000,1000]

#####Output Format

Une ligne pour chaque simulation indiquant le montant d'argent selon le type d'investisseur. Le nombre doit être arrondi et contenir en tout temps 2 chiffres après la virgule.

#####Sample Input

    3
    2
    0
    75
    1 2 0.5 10 0.5 20
    1 2 0.5 0 0.5 25
    2
    1
    30
    1 2 0.5 10 0.5 20
    1 2 0.5 0 0.5 25
    3
    0
    50
    1 5 0.5 10 0.5 20
    1 3 0.5 0 0.5 25
    3 7 0.1 0 0.7 10 0.2 7

#####Sample Output

    15.00
    25.00
    20.90

#####Explanation

Simulation 1: le client ayant un profil sécuritaire devra prioriser le premier placement, car il peut s'attendre à avoir un montant final de 15.00 en prenant compte du risque (0.5*10 + 0.5*20). Le second placement quant à lui est moins indiqué pour ce client, car il peut seulement s'attendre à en tirer 12.50 avec le calcul du risque (0.5*0 + 0.5*25).

Simulation 2: Le client ayant un profil très téméraire, le risque ne s'applique pas. Le premier placement offre donc au client la possibilité de générer 20.00 alors que le second permet au client d'obtenir un maximum de 25.00. Le montant maximal qu'il peut obtenir sera donc de 25.00.

Simulation 3: Le client ayant un profil sécuritaire il faut tenir compte du risque. Le premier placement devant être acheter en date du 1er jour et vendu le 5em génère un profit de 15.00 avec le calcul du risque (0.5*10 + 0.5*20). Par contre le second placement génère un profit de 12.50 avec risque (0.5*0 + 0.5*25) entre le 1er jour et le 3em jours. Le 3em placement pouvant être acheté le jour 3 génère un profit de 8.40 avec le calcul du risque (0.1*0 + 1.7*10 + 0.2*7). Puisqu'il est impossible d'avoir 2 placements de façon simultanée, il est impossible de prendre les placements 1 et 3 en même temps. Le choix du placement 2 permet cependant de prendre le placement 3 vue que la vente s'effectue la même journée que l'achat.
