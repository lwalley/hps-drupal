/**
 * @file
 * A JavaScript file for the mblhistory theme.
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.mblhistory = {
    weight: -50,
    attach: function (context, settings) {

      $('#navigation', context).once('mblhistory', function () {

        Drupal.theme.hpszenSubmenuToggle = function () {
          return '';
        };

        Drupal.theme.hpszenSubmenuToggleClosed = function () {
          return '';
        };

        Drupal.theme.hpszenSubmenuToggleOpen = function () {
          return '';
        };

        Drupal.theme.hpszenCyclingNav = function () {
          return '<div class="nav">' +
                 '  <a href="#" title="' +
                 Drupal.t("Javascript trigger to display previous slide.") +
                 '" id="hpszen-slide-previous">' + Drupal.t('Previous slide') + '</a>' +
                 '  <a href="#" title="' +
                 Drupal.t("Javascript trigger to display next slide.") +
                 '" id="hpszen-slide-next">' + Drupal.t('Next slide') + '</a>' +
                 '</div>';
        };

      });
    }
  };

})(jQuery, Drupal, this, this.document);

