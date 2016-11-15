$("#contact-form").submit(function() {
    $.ajax({
        url: "//formspree.io/antoine.boisier@polyalgo.org",
        method: "POST",
        data: { _subject: "Nouveau message de " + $("#contact-name").val(),
                nom:      $("#contact-name").val(),
                _replyto: $("#contact-email").val(),
                _gotcha:  $("#contact-gotcha").val(),
                message:  $("#contact-message").val() },
        dataType: "json"
    });
 
    $("#contact-form").collapse();
    $("#contact-feedback").fadeIn(50);

    return false;
});