/**
 * @file
 * A JavaScript file for the mblexhibitlinear theme.
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.mblexhibitlinear = {
    weight: -50,
    attach: function (context, settings) {
      if (Drupal.settings.hpszen === undefined) {
        Drupal.settings.hpszen = {};
      }
      Drupal.settings.hpszen.navigationBreakpoint    = 841;
      Drupal.settings.hpszen.narrativeMenuBreakpoint = 850;

      // Stick sticky things
      $('.node-type-hps-exhibit-narrative #basic__one', context).once('mblexhibitlinear', function () {
        if ($().fixedsticky) {
          if ( $.browser.safari === true && /chrome/.test(navigator.userAgent.toLowerCase())) {
            $.browser.safari = false;
          }
          $(this).once('adjustSticky', function () {
            if ($(window).width() > 850) {
              var stickyThing = $(this);
              if ($.browser.safari === true ||
                 (stickyThing.offset().top + stickyThing.height()) < $(window).height()) {
                stickyThing.addClass('fixedsticky');
                stickyThing.fixedsticky();
              }
            }
          });


          $(window).bind('load resize orientationchange', function() {
            $('.node-type-hps-exhibit-narrative #basic__one').trigger('adjustSticky');
          });
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);


