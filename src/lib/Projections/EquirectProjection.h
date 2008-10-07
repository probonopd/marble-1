//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2007      Inge Wallin  <ingwa@kde.org>
//


#ifndef EQUIRECTPROJECTION_H
#define EQUIRECTPROJECTION_H


/** @file
 * This file contains the headers for EquirectProjection.
 *
 * @author Inge Wallin  <inge@lysator.liu.se>
 */


#include "AbstractProjection.h"


namespace Marble
{

/**
 * @short A class to implement the Equirectangular projection used by the "Flat Map" view.
 */

class EquirectProjection : public AbstractProjection
{
    // Not a QObject so far because we don't need to send signals.
 public:

    /**
     * @brief Construct a new EquirectProjection.
     */
    explicit EquirectProjection();

    virtual ~EquirectProjection();

    AbstractProjectionHelper *helper();

    /**
     * @brief Get the screen coordinates corresponding to geographical coordinates in the map.
     * @param lon    the lon coordinate of the requested pixel position
     * @param lat    the lat coordinate of the requested pixel position
     * @param x      the x coordinate of the pixel is returned through this parameter
     * @param y      the y coordinate of the pixel is returned through this parameter
     * @return @c true  if the geographical coordinates are visible on the screen
     *         @c false if the geographical coordinates are not visible on the screen
     */
    bool screenCoordinates( const qreal lon, const qreal lat,
                            const ViewportParams *params,
                            int& x, int& y,
                            CoordinateType coordType = originalCoordinates );

    bool screenCoordinates( const GeoDataCoordinates &geopoint, 
                            const ViewportParams *params,
                            int &x, int &y, bool &globeHidesPoint );

    bool screenCoordinates( const GeoDataCoordinates &coordinates,
                            const ViewportParams *viewport,
                            int *x, int &y, int &pointRepeatNum,
                            bool &globeHidesPoint );

    bool screenCoordinates( const GeoDataLineString &lineString, 
                            const ViewportParams *viewport,
                            QVector<QPolygon *> &polygons );

    bool screenCoordinates( const GeoDataLinearRing &linearRing, 
                            const ViewportParams *viewport,
                            QVector<QPolygon *> &polygons );

    /**
     * @brief Get the earth coordinates corresponding to a pixel in the map.
     * @param x      the x coordinate of the pixel
     * @param y      the y coordinate of the pixel
     * @param lon    the longitude angle is returned through this parameter
     * @param lat    the latitude angle is returned through this parameter
     * @return @c true  if the pixel (x, y) is within the globe
     *         @c false if the pixel (x, y) is outside the globe, i.e. in space.
     */
    bool geoCoordinates( const int x, const int y,
                         const ViewportParams *params,
                         qreal& lon, qreal& lat,
                         GeoDataCoordinates::Unit unit = GeoDataCoordinates::Degree );

    /**
     * @brief Get a quaternion representing a point on the earth corresponding to a pixel in the map.
     * @param x  the x coordinate of the pixel
     * @param y  the y coordinate of the pixel
     * @param q  the out parameter where the result is returned
     * @return @c true  if the pixel (x, y) is within the globe
     *         @c false if the pixel (x, y) is outside the globe, i.e. in space
     */
    bool geoCoordinates( int x, int y, 
                         const ViewportParams *params,
                         Quaternion &q );

    GeoDataLatLonAltBox latLonAltBox( const QRect& screenRect,
                                      const ViewportParams *viewport );

    bool mapCoversViewport( const ViewportParams *viewport ) const;

 private:
    //EquirectProjectionPrivate  * const d;
};

}

#endif // EQUIRECTPROJECTION_H
