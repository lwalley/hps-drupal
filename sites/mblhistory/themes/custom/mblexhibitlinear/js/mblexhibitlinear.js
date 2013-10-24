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
      Drupal.settings.hpszen.navigationBreakpoint = 841;
    }
  };

})(jQuery, Drupal, this, this.document);


