window.onload = function () {
	$('.fr').removeClass('hide-lang');
	$('.en').addClass('hide-lang');
}

$("#bouton-anglais").click(function() {
	$('.en').removeClass('hide-lang');
	$('.fr').addClass('hide-lang');
});

$("#bouton-francais").click(function() {
	$('.fr').removeClass('hide-lang');
	$('.en').addClass('hide-lang');
});

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
