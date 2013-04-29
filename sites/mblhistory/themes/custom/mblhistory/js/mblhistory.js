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
        }

        Drupal.theme.hpszenSubmenuToggleOpen = function () {
          return '';
        }

      });
    }
  };

})(jQuery, Drupal, this, this.document);

