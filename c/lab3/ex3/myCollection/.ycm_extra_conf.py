import os
import ycm_core

flags = [
  '-x',
  'c++',
  '-Wall',
  '-Wextra',
  '-Werror',
  '-I./include/',
  ]

SOURCE_EXTENSIONS = [ '.cpp', '.cxx', '.cc', '.c', ]

def Settings( **kwargs ):
  return {
  'flags': flags,
  }
