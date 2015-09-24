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
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // Step 1
    //$('.view-top-films-list .views-field-title').mouseover(function(){
    //  console.log($(this).next().html());
    //});

    //Step 2
    $('.view-top-films-list .views-field-title a').mouseover(function(){

      //Get the tooltip from the next column along
      tooltip_text = $(this).parent().parent().next().html();

      //Create a div which is appended to the outside of the a tage.
      $('<div class="top-ten-tooltip">' + tooltip_text + '</div>').appendTo($(this).parent());
    });

    //When me mouse off a link in the top ten list view
    $('.view-top-films-list .views-field-title a').mouseout(function(){

     //Remove any tooltips.
      $('.top-ten-tooltip').remove();
    });

  }
};


})(jQuery, Drupal, this, this.document);
