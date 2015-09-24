/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.movie_user = {
  attach: function(context, settings) {

    // onclick handler generates the new random sort from the view page url
    $( ".suggest-more-button" ).click(function() {
      //alert( "Handler for .click() called." );

      uid = $(this).attr('data-uid');
      //console.log(uid)
      if (uid > 0) {
        $.get( Drupal.settings.basePath + Drupal.settings.movie_suggest_url + '/' + uid, function(data, status) {
          //console.log( data );
          $( ".movie-suggestions-by-genre" ).html( data );
        });
      }
    });
  }
};

})(jQuery, Drupal, this, this.document);
