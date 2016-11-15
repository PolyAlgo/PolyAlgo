Contribuer à PolyAlgo
===
PolyAlgo est un club étudiant d'algorithmie à l'école Polytechnique de Montréal.  Toute contribution est grandement appréciée! 

+ [Challenges et solutions](#sol)
+ [Site web](#web)
+ [Problèmes et bugs](#bug)

<a name="sol"></a> Challenges et solutions
---
Pour ajouter un challenge, veuillez créer, s'il n'existe pas déjà, un dossier dans "Documentation" dont le nom sera la compétition dont provient le challenge. Ensuite, veuillez créer un dossier dont le nom sera celui du challenge suivi du nombre de solution que contiendra le dossier entre parenthèses. Par exemple :

    Documentation/Nom de la compétition/Nom du challenge (0)

Ensuite, créez un fichier README.md qui contiendra l'énoncé du challenge. Veuillez, s'il vous plait, respecter le style général des énoncés déjà présent ([voici](https://github.com/Aboisier/Polyalgo/tree/gh-pages/Documentation/Comp%C3%A9tion%20informatique%20CEGInfo%202016/Le%20passeur%20(1)) un exemple). Les points à retenir sont les suivants:
+ Inclure un lien vers le challenge original
+ Mettre le titre du challenge comme un titre de niveau 1. (#)
+ Mettre les inter-titres (contexte, exemple, etc) en titre de niveau 2 (##)
+ Inclure des exemples d'input/output
  + Mettre les inter-titres (input example, output example, explanation, etc.) en titre de niveau 5 (#####)
  + Mettre les exemples d'input/output en paragraphe de code (mettre quatre espaces avant chaque ligne)

Pour ajouter une solution à un énoncé, il suffit d'effectuer un pull request avec votre fichier ajouté. Il faut également mettre à jour le nombre de solutions entre parenthèses dans le nom du dossier. Il est conseillé de commenter son code et d'inclure un header au début de votre fichier qui devrait contenir le nom du fichier, votre nom, la date et une description indiquant le nombre de testcases que résoud votre solution, ou le nombre de points qu'elle donne, un lien vers le challenge original, ainsi que toute autre information pertinente. L'utilisation de Bitly ou TinyURL est conseillée. Par exemple :

    //-----------------------------------------------------------------------------
    //     Fichier : Lorem ipsum - Jean-Guy Poitras.cpp
    //      Auteur : Jean-Guy Poitras
    //        Date : 2016-10-03
    // Description : Ma solution pour le challenge Lorem ipsum (http://bit.ly/1TXgt4s).
    //               Cette solution m'a valu 89/100 points.
    //-----------------------------------------------------------------------------

<a name="web"></a> Site web
---
Pour participer au site web, vous pouvez consulter le fichier [TODO.md](https://github.com/Aboisier/Polyalgo/blob/gh-pages/TODO.md) qui contient une liste des choses à faire. 
+ Veuillez respecter les conventions de programmation
+ Mettre le javascript dans des fichiers .js, le css dans des fichiers .css, pas dans les .html.
+ Préférer $("#...") à document.getElementById("...")

<a name="bug"></a> Problèmes et bugs
---
Si vous trouvez un bug, veuillez ouvrir une issue ou bien nous contacter à l'adresse suivante : info@polyalgo.org.
