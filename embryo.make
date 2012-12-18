; Drush make file for custom modules and themes for the Embryo Project
; Encyclopedia

api = 2
core = 7.x

; Set projects defaults for modules and themes
defaults[projects][subdir] = "custom"

; Theme
projects[embryo][type] = theme
projects[embryo][download][type] = get
projects[embryo][download][url] = https://github.com/mbl-cli/hps-drupal/archive/<replaceme:tagname>.zip
projects[embryo][download][subtree] = hps-drupal-<replaceme:tagname>/sites/embryo/themes/custom/embryo

; Modules
projects[embryo_dspaced][type] = module
projects[embryo_dspaced][download][type] = get
projects[embryo_dspaced][download][url] = https://github.com/mbl-cli/hps-drupal/archive/<replaceme:tagname>.zip
projects[embryo_dspaced][download][subtree] = hps-drupal-<replaceme:tagname>/sites/embryo/modules/custom/embryo_dspaced
