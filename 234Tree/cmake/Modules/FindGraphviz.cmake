# - Try to find Graphviz
# Once done this will define
#
#  GRAPHVIZ_FOUND - system has Graphviz
#  GRAPHVIZ_INCLUDE_DIR - the Graphviz include directory
#  GRAPHVIZ_LIBRARY - Link these to use Graphviz
#  GRAPHVIZ_DEFINITIONS - Compiler switches required for using Graphviz

# Copyright (c) 2009, Adrien Bustany, <madcat@mymadcat.com>
#
# Redistribution and use is allowed according to the terms of the GPLv3+ license.

IF (GRAPHVIZ_INCLUDE_DIR AND GRAPHVIZ_CDT_LIBRARY AND GRAPHVIZ_GVC_LIBRARY AND GRAPHVIZ_CGRAPH_LIBRARY AND GRAPHVIZ_GRAPH_LIBRARY AND GRAPHVIZ_PATHPLAN_LIBRARY)
    SET(GRAPHVIZ_FIND_QUIETLY TRUE)
ENDIF (GRAPHVIZ_INCLUDE_DIR AND GRAPHVIZ_CDT_LIBRARY AND GRAPHVIZ_GVC_LIBRARY AND GRAPHVIZ_CGRAPH_LIBRARY AND GRAPHVIZ_GRAPH_LIBRARY AND GRAPHVIZ_PATHPLAN_LIBRARY)

FIND_PATH( GRAPHVIZ_INCLUDE_DIR graphviz/graph.h)

FIND_LIBRARY( GRAPHVIZ_CDT_LIBRARY NAMES cdt )
FIND_LIBRARY( GRAPHVIZ_GVC_LIBRARY NAMES gvc )
FIND_LIBRARY( GRAPHVIZ_CGRAPH_LIBRARY NAMES cgraph )
FIND_LIBRARY( GRAPHVIZ_GRAPH_LIBRARY NAMES graph )
FIND_LIBRARY( GRAPHVIZ_PATHPLAN_LIBRARY NAMES pathplan )

IF (GRAPHVIZ_INCLUDE_DIR AND GRAPHVIZ_CDT_LIBRARY AND GRAPHVIZ_GVC_LIBRARY AND GRAPHVIZ_CGRAPH_LIBRARY AND GRAPHVIZ_GRAPH_LIBRARY AND GRAPHVIZ_PATHPLAN_LIBRARY)
   SET(GRAPHVIZ_FOUND TRUE)
ELSE (GRAPHVIZ_INCLUDE_DIR AND GRAPHVIZ_CDT_LIBRARY AND GRAPHVIZ_GVC_LIBRARY AND GRAPHVIZ_CGRAPH_LIBRARY AND GRAPHVIZ_GRAPH_LIBRARY AND GRAPHVIZ_PATHPLAN_LIBRARY)
   SET(GRAPHVIZ_FOUND FALSE)
ENDIF (GRAPHVIZ_INCLUDE_DIR AND GRAPHVIZ_CDT_LIBRARY AND GRAPHVIZ_GVC_LIBRARY AND GRAPHVIZ_CGRAPH_LIBRARY AND GRAPHVIZ_GRAPH_LIBRARY AND GRAPHVIZ_PATHPLAN_LIBRARY)

IF (GRAPHVIZ_FOUND)
  IF (NOT GRAPHVIZ_FIND_QUIETLY)
    MESSAGE(STATUS "Found Graphviz: ${GRAPHVIZ_CDT_LIBRARY} ${GRAPHVIZ_GVC_LIBRARY} ${GRAPHVIZ_CGRAPH_LIBRARY} ${GRAPHVIZ_GRAPH_LIBRARY} ${GRAPHVIZ_PATHPLAN_LIBRARY}")
  ENDIF (NOT GRAPHVIZ_FIND_QUIETLY)
ELSE (GRAPHVIZ_FOUND)
  IF (GRAPHVIZ_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could NOT find Graphivz")
  ENDIF (GRAPHVIZ_FIND_REQUIRED)
ENDIF (GRAPHVIZ_FOUND)


# Added by Vaios Papaspyros
# Custom code to determine whether cgraph or graph is found 
#
# Defining those as well
#
# GRAPHVIZ_CGRAPH_FOUND
# GRAPHVIZ_GRAPH_FOUND
# GRAPHVIZ_GVC_FOUND
#


# CGRAPH
IF (GRAPHVIZ_CGRAPH_LIBRARY)
	MESSAGE(STATUS "Working with - CGRAPH")
	SET(GRAPHVIZ_CGRAPH_FOUND TRUE)
ELSE (GRAPHVIZ_CGRAPH_LIBRARY)
	SET(GRAPHVIZ_CGRAPH_FOUND FALSE)
ENDIF (GRAPHVIZ_CGRAPH_LIBRARY)

# GRAPH
IF (GRAPHVIZ_GRAPH_LIBRARY)
	MESSAGE(STATUS "Working with - GRAPH")
	SET(GRAPHVIZ_GRAPH_FOUND TRUE)
ELSE (GRAPHVIZ_GRAPH_LIBRARY)
	SET(GRAPHVIZ_GRAPH_FOUND FALSE)
ENDIF (GRAPHVIZ_GRAPH_LIBRARY)

# GVC 
IF (GRAPHVIZ_GVC_LIBRARY)
	MESSAGE(STATUS "gvc - FOUND")
	SET(GRAPHVIZ_GVC_FOUND TRUE)
ELSE (GRAPHVIZ_GVC_LIBRARY)
	SET(GRAPHVIZ_GVC_FOUND FALSE)
ENDIF (GRAPHVIZ_GVC_LIBRARY)