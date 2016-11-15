// Ref : https://goo.gl/Dg96b2
function getParameterByName(name, url) {
    if (!url) url = window.location.href;
    name = name.replace(/[\[\]]/g, "\\$&");
    var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
        results = regex.exec(url);
    if (!results) return null;
    if (!results[2]) return '';
    return decodeURIComponent(results[2].replace(/\+/g, " "));
}

window.onload = function () {
	//alert(getParameterByName("lang"))
	if(getParameterByName("lang") == 'en') {
		$('.en').removeClass('hide-lang');
		$('.fr').addClass('hide-lang');
	}
	else {
		$('.fr').removeClass('hide-lang');
		$('.en').addClass('hide-lang');
	}
}

function rotateOnClick(glyph, name) {

	 $(name).collapse("toggle");

	 if($(name).attr("aria-expanded") == "true")
	 {
		 $(glyph).addClass("rotate-expand");
		 $(glyph).removeClass("rotate-collapse");
	 }
	 else
	 {
		 $(glyph).addClass("rotate-collapse");
		 $(glyph).removeClass("rotate-expand");
	 }
}
