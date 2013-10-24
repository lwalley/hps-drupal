/**
 * @file
 * A JavaScript file for the mblhistory theme.
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.mblhistory = {
    weight: -50,
    attach: function (context, settings) {

      $('.slides', context).once('hpszen', function () {

        if ('cycle' in $.fn) {

          Drupal.theme.hpszenCyclingNavigation = function () {
            return '<div class="slideshow__navigation">' +
                   '  <a href="#" title="' +
                      Drupal.t("Visually display the previous slide.") +
                      '" class="slideshow__navigation__previous">' +
                      Drupal.t('Previous slide') + '</a>' +
                   '  <a href="#" title="' +
                      Drupal.t("Visually display the next slide.") +
                      '" class="slideshow__navigation__next">' +
                      Drupal.t('Next slide') + '</a>' +
                   '</div>';
          };
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);

