{
  "targets": [
    {
      "target_name": "addon",
      "sources": ["addon.cc", "Test.cc"],
      "include_dirs": ["<!(node -e \"require('nan')\")"],
      "cflags": ["-Wall", "-Werror"]
    }
  ]
}
