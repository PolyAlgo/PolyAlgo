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