const solutions = 'https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation';

function getUser(user, callback)
{
	$.getJSON('https://api.github.com/users' + user, callback);
}

var write = function (data)
{
	$.each(data, function (index, val) {
		console.log(val.name);
		if(val.name != "undefined")
		{
			str = '<div class="row">' + 
					'<div class="col-lg-12">';
		}

	});
}

$.getJSON('https://api.github.com/repos/Aboisier/Polyalgo/contents/Documentation', write);
getUser('', write);