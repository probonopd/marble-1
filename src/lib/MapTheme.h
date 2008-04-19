//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2006-2007 Torsten Rahn <tackat@kde.org>"
// Copyright 2007      Inge Wallin  <ingwa@kde.org>"
//


#ifndef MAPTHEME_H
#define MAPTHEME_H


#include <QtCore/QObject>
#include <QtGui/QColor>
#include <QtGui/QPixmap>

#include "marble_export.h"

class QStandardItemModel;


typedef struct
{
    bool     enabled;
    QString  type;
    QString  name;
    QString  dem;
} DgmlLayer;


class QDomElement;


class LegendItem
{
 public:
    LegendItem();
    ~LegendItem() {}

    QColor   background()             const { return m_background; }
    void     setBackground( QColor bg )     { m_background = bg;   }
    QPixmap  symbol()                 const { return m_symbol;     }
    void     setSymbol( QPixmap sym )       { m_symbol = sym;      }
    QString  text()                   const { return m_text;       }
    void     setText( QString txt )         { m_text = txt;        }

 private:
    QColor   m_background;
    QPixmap  m_symbol;
    QString  m_text;
};


class LegendSection
{
 public:
    LegendSection() 
        : m_heading(),
          m_items()
    { }
    ~LegendSection() {
        qDeleteAll( m_items );
        m_items.clear();
    };

    QString  name()                           const { return m_name; }
    void     setName( QString name )                { m_name = name;   }
    QString  heading()                        const { return m_heading; }
    void     setHeading( QString hd )               { m_heading = hd;   }
    bool     checkable()                      const { return m_checkable; }
    void     setCheckable( bool  checkable )        { m_checkable = checkable; }
    int      spacing()                        const { return m_spacing; }
    void     setSpacing( int spacing )              { m_spacing = spacing; }
    QList< LegendItem*> items()               const { return m_items;   }
    void                addItem( LegendItem *item ) { m_items.append( item ); }

    void     clear()
    {
        m_heading.clear();
        m_items.clear();
    }

 private:
    QString               m_name;
    QString               m_heading;
    bool                  m_checkable;
    int                   m_spacing;
    QList< LegendItem* >  m_items;
};


class MapTheme : public QObject
{
    Q_OBJECT

public:
    MapTheme(QObject *parent = 0);
    ~MapTheme();

    int open( const QString& path );

    QString name()          const { return m_name;        }
    QString prefix()        const { return m_prefix;      }
    QString icon()          const { return m_icon;        }
    QColor  labelColor()    const { return m_labelColor;  }
    int     minimumZoom()   const { return m_minimumZoom; }
    int     maximumZoom()   const { return m_maximumZoom; }
    QList<LegendSection*> legend() const { return m_legend; }

    QColor oceanColor()         const { return m_oceanColor;         }
    QColor landColor()          const { return m_landColor;          }
    QColor countryBorderColor() const { return m_countryBorderColor; }
    QColor stateBorderColor()   const { return m_stateBorderColor;   }
    QColor lakeColor()          const { return m_lakeColor;          }
    QColor riverColor()         const { return m_riverColor;         }

    QString tilePrefix()    const { return m_prefix;      }
    QString description()   const { return m_description; }
    QString installMap()    const { return m_installmap;  }

    DgmlLayer bitmaplayer() const { return m_bitmaplayer; }
    DgmlLayer vectorlayer() const { return m_vectorlayer; }

    static QStringList findMapThemes( const QString& );
    static QStandardItemModel* mapThemeModel( const QStringList& stringlist );

private:
    bool parseLegend( QDomElement &legendElement );
    bool parseLegendSection( QDomElement   &legendSectionElement,
                             LegendSection *sectionItem );
    bool parseLegendItem( QDomElement &legendItemElement,
                          LegendItem  *legendItem );


private:
    QString    m_name;
    QString    m_prefix;
    QString    m_icon;
    QColor     m_labelColor;
    int        m_minimumZoom;
    int        m_maximumZoom;
    QList<LegendSection*>  m_legend;

    QColor     m_oceanColor;
    QColor     m_landColor;
    QColor     m_countryBorderColor;
    QColor     m_stateBorderColor;
    QColor     m_lakeColor;
    QColor     m_riverColor;

    QString    m_tileprefix;
    QString    m_description;
    QString    m_installmap;
    DgmlLayer  m_vectorlayer;
    DgmlLayer  m_bitmaplayer;
};


#endif // MAPTHEME_H
