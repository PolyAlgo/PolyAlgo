$("#contact-send").click(function() {
    var link = "mailto:aboisiermichaud@gmail.com"
             + "?cc=a.boisier@polymtl.ca"
             + "&subject=" + escape("Whadup boss")
             + "&body=" + escape($("#contact-message").value) + "#contact";

    window.location.href = link;
});