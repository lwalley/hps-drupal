; Drush make file for custom modules and themes for MBL History

api = 2
core = 7.x

; Set projects defaults for modules and themes
defaults[projects][subdir] = "custom"

; Themes
projects[mblhistory][type] = theme
projects[mblhistory][download][type] = get
projects[mblhistory][download][url] = https://github.com/mbl-cli/hps-drupal/archive/2013.10.30.01.zip
projects[mblhistory][download][subtree] = hps-drupal-2013.10.30.01/sites/mblhistory/themes/custom/mblhistory

projects[mblexhibitlinear][type] = theme
projects[mblexhibitlinear][download][type] = get
projects[mblexhibitlinear][download][url] = https://github.com/mbl-cli/hps-drupal/archive/2013.10.30.01.zip
projects[mblexhibitlinear][download][subtree] = hps-drupal-2013.10.30.01/sites/mblhistory/themes/custom/mblexhibitlinear

; Modules
projects[mblhistory_dspaced][type] = module
projects[mblhistory_dspaced][download][type] = get
projects[mblhistory_dspaced][download][url] = https://github.com/mbl-cli/hps-drupal/archive/2013.10.30.01.zip
projects[mblhistory_dspaced][download][subtree] = hps-drupal-2013.10.30.01/sites/mblhistory/modules/custom/mblhistory_dspaced

projects[mblhistory_home][type] = module
projects[mblhistory_home][download][type] = get
projects[mblhistory_home][download][url] = https://github.com/mbl-cli/hps-drupal/archive/2013.10.30.01.zip
projects[mblhistory_home][download][subtree] = hps-drupal-2013.10.30.01/sites/mblhistory/modules/custom/mblhistory_home

projects[mblhistory_participate][type] = module
projects[mblhistory_participate][download][type] = get
projects[mblhistory_participate][download][url] = https://github.com/mbl-cli/hps-drupal/archive/2013.10.30.01.zip
projects[mblhistory_participate][download][subtree] = hps-drupal-2013.10.30.01/sites/mblhistory/modules/custom/mblhistory_participate

