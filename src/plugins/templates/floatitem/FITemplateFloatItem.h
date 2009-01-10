//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008 Inge Wallin <inge@lysator.liu.se>"
//

//
// This class is a template Float Item plugin.
//


#ifndef FITEMPLATE_FLOAT_ITEM_H
#define FITEMPLATE_FLOAT_ITEM_H


// Qt
#include <QtCore/QObject>

// Marble
#include "GeoDataLatLonAltBox.h"
#include "MarbleAbstractFloatItem.h"


class QSvgRenderer;


/**
 * @short The class that creates a ... Float Item
 *
 */

class FITemplateFloatItem  : public MarbleAbstractFloatItem
{
    Q_OBJECT
    Q_INTERFACES( MarbleRenderPluginInterface )
    MARBLE_PLUGIN(FITemplateFloatItem)

 public:
    explicit FITemplateFloatItem( const QPointF &point = QPointF( -1.0, 10.0 ),
				  const QSizeF &size = QSizeF( 75.0, 75.0 ) );

    // ----------------------------------------------------------------
    // The following functions are defined in MarbleRenderPluginInterface.h
    // and MUST be part of the plugin.  See that file for documentation.
    //
    // Note that the class MarbleAbstractFloatItem provides default 
    // implementations for many of them.
    //

    ~FITemplateFloatItem ();

    QStringList backendTypes() const;

    // Provided by MarbleAbstractFloatItem and should not be implemented.
    //
    // QString renderPolicy() const;
    // QStringList renderPosition() const;

    QString name() const;

    QString guiString() const;

    QString nameId() const;

    QString description() const;

    QIcon icon() const;

    void initialize();

    bool isInitialized() const;

    // Provided by MarbleAbstractFloatItem and should not be implemented.
    //
    // bool render( GeoPainter *painter, ViewportParams *viewport,
    //              const QString &renderPos, GeoSceneLayer *layer);

    QPainterPath backgroundShape() const;

    // End of MarbleRenderPluginInterface functions.
    // ----------------------------------------------------------------

    bool needsUpdate( ViewportParams *viewport );

    bool renderFloatItem( GeoPainter *painter, ViewportParams *viewport,
			  GeoSceneLayer * layer = 0 );

 private:
    Q_DISABLE_COPY( FITemplateFloatItem )

    QSvgRenderer  *m_svgobj;
    QPixmap        m_compass;

    /// allowed values: -1, 0, 1; default here: 0. FIXME: Declare enum
    int            m_polarity;
};

#endif
