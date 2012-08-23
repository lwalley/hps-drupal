This directory should be used to place libraries, modules, patches and themes that are common to all sites. If modules are only applicable to a single site then they should be placed in sites/[sitename]/modules/[contributed or custom].

Keep common contributed modules and custom in-house modules separate to allow easier maintenance and upgrades in the future. Place common downloaded non-core modules in sites/all/modules/contributed/ and place common custom built modules in sites/all/modules/custom/.

Never commit manual edits to contributed modules. Track all modifications made to downloaded contributed modules by creating and applying patches. Store those patches in sites/all/patches.

Follow Drupal recommendations for creating patches (http://drupal.org/node/707484 and http://drupal.org/node/1054616) by cloning the module code into a separate repository and creating the patch there. Patch filenames shoulf follow the naming convention:

  [project_name]-[short_description]-[issue-number]-[comment-number].patch

Patches that are created in a different repository following Drupal recommendations cannot be applied to this repository using git apply (http://drupal.org/patch/apply), instead navigate to the root of the module and use:

  patch -p1 < example-bug_fix-12345.patch




