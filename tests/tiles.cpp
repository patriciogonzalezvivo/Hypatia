
#include <string>
#include <sstream>
#include <unistd.h>
#include <iostream>

#include "hypatia/CoordOps.h"
#include "hypatia/ProjOps.h"
#include "hypatia/MathOps.h"

int main(int argc, char **argv) {

    double lat = 40.785091;
    double lng = -73.968285;
    int zoom = 16;

    hypatia::Geodetic loc = hypatia::Geodetic(lng, lat, 0.0, hypatia::DEGS, hypatia::KM);
    std::cout << loc.getLongitude(hypatia::DEGS) << "," << loc.getLatitude(hypatia::DEGS) << std::endl;

    hypatia::UTM utm = loc.getUTM();
    std::cout << "utm: " << utm << std::endl;

    hypatia::Vector2 mercator = hypatia::ProjOps::toMercator(loc);
    std::cout << "Mercator: " << mercator << std::endl;

    hypatia::Tile tile = hypatia::CoordOps::toTile(loc, zoom);
    std::cout << tile << std::endl;

    std::cout << "Up     : " << tile.up() << std::endl;
    std::cout << "left   : " << tile.left() << std::endl;
    std::cout << "down   : " << tile.down() << std::endl;
    std::cout << "right  : " << tile.right() << std::endl;
    std::cout << "parent : " << tile.getParent() << std::endl;
    std::cout << "zoom -2: " << tile.zoom(-2) << std::endl;
    std::cout << "at 16  : " << tile.getTileAtZoom(16) << std::endl;
    std::cout << "childs : " << tile.getParent().getChild(0, 20) << std::endl;
    std::cout << "         " << tile.getParent().getChild(1, 20) << std::endl;
    std::cout << "         " << tile.getParent().getChild(2, 20) << std::endl;
    std::cout << "         " << tile.getParent().getChild(3, 20) << std::endl;

    std::cout << "uv      : " << tile.getUV() << std::endl;
    std::cout << "mercator: " << tile.getMercator() << std::endl;
    std::cout << "location: " << tile.getGeodetic() << std::endl;

    for (int i = 16; i < 26; i++)
        std::cout << "Zoom " << std::setw(2) << i << " : " << std::setw(6) << hypatia::Tile::getMetersPerTileAt(i) << "m" << std::endl;
 
    std::cout <<  tile.getProviderURL(hypatia::NEXTZEN_JSON) << std::endl;
    std::cout <<  tile.getProviderURL(hypatia::NEXTZEN_MVT) << std::endl;
    
    std::cout <<  tile.getProviderURL(hypatia::OSM) << std::endl;

    std::cout <<  tile.getProviderURL(hypatia::BING) << std::endl;

    std::cout <<  tile.getProviderURL(hypatia::MICROSOFT_BASE) << std::endl;

    std::cout <<  tile.getProviderURL(hypatia::STAMEN_TONER) << std::endl;
    std::cout <<  tile.getProviderURL(hypatia::STAMEN_TONER_HYBRID) << std::endl;
    std::cout <<  tile.getProviderURL(hypatia::STAMEN_TONER_LABELS) << std::endl;
    std::cout <<  tile.getProviderURL(hypatia::STAMEN_TONER_LINES) << std::endl;
    std::cout <<  tile.getProviderURL(hypatia::STAMEN_TONER_BACKGROUND) << std::endl;
    std::cout <<  tile.getProviderURL(hypatia::STAMEN_TERRAIN) << std::endl;
    return 0;
}