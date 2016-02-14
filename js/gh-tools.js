const solutions = 'https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation';

function getUser(user, callback)
{
	$.getJSON('https://api.github.com/users' + user, callback);
}

var write = function (data)
{
	$.each(data, function (index, val) {
		
		if(val.name != undefined)
		{
			console.log(val.name);
			str = '<div class="row"> <div class="col-lg-12">' + 
					'<p  class="competition-name" onclick="rotateOnClick(\'#' + val.name.replace(/\s+/g, '') + 'glyph\', \'#' + val.name.replace(/\s+/g, '') + '\')"><span id=\'' + val.name.replace(/\s+/g, '') + 'glyph\' class="glyphicon glyphicon-chevron-down rotate-collapse"></span> '+ val.name + ' </p>' +
					'<div id=\''+ val.name.replace(/\s+/g, '')+ '\' aria-expanded=\'false\' class=\'collapse\'> Lorem ipsum dolor sit amet, consectetur adipisicing elit, </div> </div></div><br>';
			$('#competitions').append(str);
			console.log(str);
		}

	});
}

$.getJSON('https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation', write);
getUser('', write);