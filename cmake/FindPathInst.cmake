message(STATUS "Finding PathInst")

set(PathInst_DIR "/Users/ird/dev/github/iandinwoodie/pathinst/build")

function(target_enable_pathinst target)
  set_target_properties(${target}
    PROPERTIES
      CXX_COMPILER_LAUNCHER "${PathInst_DIR}/pcc"
  )
endfunction()
