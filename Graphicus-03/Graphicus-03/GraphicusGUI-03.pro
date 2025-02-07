TEMPLATE     = vcapp
TARGET       = GraphicusGUI-03
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h canevas.h carre.h cercle.h coordonnee.h couche.h forme.h rectangle.h vecteur.h
SOURCES     += GraphicusGUI-03.cpp monInterface.cpp canevas.cpp carre.cpp cercle.cpp couche.cpp forme.cpp rectangle.cpp vecteur.cpp
INCLUDEPATH += "../Graphicus-03"
LIBS        += "../Graphicus-03/graphicusGUI.lib"
QT          += widgets
