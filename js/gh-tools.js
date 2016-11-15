// Le lien vers le dossier contenant tous les compétitions et solutions.
const dir = 'https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation';

/** 
 * Écrit le nom de chaque challenge d'une catégorie avec un lien vers
 * le dossier contenant l'énoncé et les solutions.
 * @param {JSON} data - La réponse JSON de call de l'api de GitHub.
 * @param {state} state - L'état de la réponse du call de l'api de GitHub.
 * @param {string} id - L'ID du div dans lequel ajouter les challenges.
 */ 
var writeChallenges = function(data, state, id)
{
	if(state == "success")
	{
		$.each(data, function (index, val) {
			
			if(val.name != undefined)
			{	
				str = '<li class=\'challenge\'><a href=\'' + val.html_url + '\'>' + val.name + '</a></li>'
		
				$('#' + id).append(str);
			}
		});
	}
}

/** 
 * Génère le html de chaque catégorie de challenge. Pour chaque dossier 
 * contenu dans  le dossier Documentation du repo, une catégorie est créée.
 * @param {JSON} data - La réponse JSON de call de l'api de GitHub.
 * @param {state} state - L'état de la réponse du call de l'api de GitHub.
 */ 
var writeCategories = function (data, state)
{
	if(state == "success")
	{
		$.each(data, function (index, val) {
			
			if(val.name != undefined)
			{	
				var name = val.name.replace(/\s+/g, '');
				
				str = '<div class="row"> <div class="col-lg-12">' + 
						'<p  class="competition-name" onclick="rotateOnClick(\'#' + name + 'glyph\', \'#' + name + '\')"><span id=\'' + name + 'glyph\' class="glyphicon glyphicon-chevron-down rotate-collapse"></span> '+ val.name + ' </p>' +
						'<div id=\''+ name + '\' aria-expanded=\'false\' class=\'collapse\'>  </div> </div></div><br>';
				$('#competitions').append(str);
				
				$.getJSON(val.url, function(data, state) { writeChallenges(data, state, name); });
			}
		});
	}
}

// Génère le code de tous les challenges solutions de la page algorithmes.
$.getJSON(dir, writeCategories);
