; Drush make file for custom modules and themes for MBL History

api = 2
core = 7.x

; Set projects defaults for modules and themes
defaults[projects][subdir] = "custom"

; Theme
projects[mblhistory][type] = theme
projects[mblhistory][download][type] = get
projects[mblhistory][download][url] = https://github.com/mbl-cli/hps-drupal/archive/<replaceme:tagname>.zip
projects[mblhistory][download][subtree] = hps-drupal-<replaceme:tagname>/sites/mblhistory/themes/custom/mblhistory

; Modules
projects[mblhistory_dspaced][type] = module
projects[mblhistory_dspaced][download][type] = get
projects[mblhistory_dspaced][download][url] = https://github.com/mbl-cli/hps-drupal/archive/<replaceme:tagname>.zip
projects[mblhistory_dspaced][download][subtree] = hps-drupal-<replaceme:tagname>/sites/mblhistory/modules/custom/mblhistory_dspaced
