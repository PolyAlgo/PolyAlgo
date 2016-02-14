const solutions = 'https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation';


var writeChallenges = function(data, state, id)
{
	if(state == "success")
	{
		//('#' + id).append('<ul>');
		$.each(data, function (index, val) {
			
			if(val.name != undefined)
			{	
				str = '<li class=\'challenge\'><a href=\'' + val.html_url + '\'>' + val.name + '</a></li>'
		
				$('#' + id).append(str);
			}
		});
		//('#' + id).append('</ul>');
	}
	
}

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

$.getJSON('https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation', writeCategories);
