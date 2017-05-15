/*****************************************************************************
* Copyright 2015-2017 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "fs/util/tacanfrequencies.h"

#include <QHash>

namespace atools {
namespace fs {
namespace util {

static QHash<QString, int> CHANNEL_DME_FREQUENCY_MAP(
  {
    {"1X", 13440},
    {"1Y", 13445},
    {"2X", 13450},
    {"2Y", 13455},
    {"3X", 13460},
    {"3Y", 13465},
    {"4X", 13470},
    {"4Y", 13475},
    {"5X", 13480},
    {"5Y", 13485},
    {"6X", 13490},
    {"6Y", 13495},
    {"7X", 13500},
    {"7Y", 13505},
    {"8X", 13510},
    {"8Y", 13515},
    {"9X", 13520},
    {"9Y", 13525},
    {"10X", 13530},
    {"10Y", 13535},
    {"11X", 13540},
    {"11Y", 13545},
    {"12X", 13550},
    {"12Y", 13555},
    {"13X", 13560},
    {"13Y", 13565},
    {"14X", 13570},
    {"14Y", 13575},
    {"15X", 13580},
    {"15Y", 13585},
    {"16X", 13590},
    {"16Y", 13595},
    {"17X", 10800},
    {"17Y", 10805},
    {"18X", 10810},
    {"18Y", 10815},
    {"19X", 10820},
    {"19Y", 10825},
    {"20X", 10830},
    {"20Y", 10835},
    {"21X", 10840},
    {"21Y", 10845},
    {"22X", 10850},
    {"22Y", 10855},
    {"23X", 10860},
    {"23Y", 10865},
    {"24X", 10870},
    {"24Y", 10875},
    {"25X", 10880},
    {"25Y", 10885},
    {"26X", 10890},
    {"26Y", 10895},
    {"27X", 10900},
    {"27Y", 10905},
    {"28X", 10910},
    {"28Y", 10915},
    {"29X", 10920},
    {"29Y", 10925},
    {"30X", 10930},
    {"30Y", 10935},
    {"31X", 10940},
    {"31Y", 10945},
    {"32X", 10950},
    {"32Y", 10955},
    {"33X", 10960},
    {"33Y", 10965},
    {"34X", 10970},
    {"34Y", 10975},
    {"35X", 10980},
    {"35Y", 10985},
    {"36X", 10990},
    {"36Y", 10995},
    {"37X", 11000},
    {"37Y", 11005},
    {"38X", 11010},
    {"38Y", 11015},
    {"39X", 11020},
    {"39Y", 11025},
    {"40X", 11030},
    {"40Y", 11035},
    {"41X", 11040},
    {"41Y", 11045},
    {"42X", 11050},
    {"42Y", 11055},
    {"43X", 11060},
    {"43Y", 11065},
    {"44X", 11070},
    {"44Y", 11075},
    {"45X", 11080},
    {"45Y", 11085},
    {"46X", 11090},
    {"46Y", 11095},
    {"47X", 11100},
    {"47Y", 11105},
    {"48X", 11110},
    {"48Y", 11115},
    {"49X", 11120},
    {"49Y", 11125},
    {"50X", 11130},
    {"50Y", 11135},
    {"51X", 11140},
    {"51Y", 11145},
    {"52X", 11150},
    {"52Y", 11155},
    {"53X", 11160},
    {"53Y", 11165},
    {"54X", 11170},
    {"54Y", 11175},
    {"55X", 11180},
    {"55Y", 11185},
    {"56X", 11190},
    {"56Y", 11195},
    {"57X", 11200},
    {"57Y", 11205},
    {"58X", 11210},
    {"58Y", 11215},
    {"59X", 11220},
    {"59Y", 11225},
    {"60X", 13330},
    {"60Y", 13335},
    {"61X", 13340},
    {"61Y", 13345},
    {"62X", 13350},
    {"62Y", 13355},
    {"63X", 13360},
    {"63Y", 13365},
    {"64X", 13370},
    {"64Y", 13375},
    {"65X", 13380},
    {"65Y", 13385},
    {"66X", 13390},
    {"66Y", 13395},
    {"67X", 13400},
    {"67Y", 13405},
    {"68X", 13410},
    {"68Y", 13415},
    {"69X", 13420},
    {"69Y", 13425},
    {"70X", 11230},
    {"70Y", 11235},
    {"71X", 11240},
    {"71Y", 11245},
    {"72X", 11250},
    {"72Y", 11255},
    {"73X", 11260},
    {"73Y", 11265},
    {"74X", 11270},
    {"74Y", 11275},
    {"75X", 11280},
    {"75Y", 11285},
    {"76X", 11290},
    {"76Y", 11295},
    {"77X", 11300},
    {"77Y", 11305},
    {"78X", 11310},
    {"78Y", 11315},
    {"79X", 11320},
    {"79Y", 11325},
    {"80X", 11330},
    {"80Y", 11335},
    {"81X", 11340},
    {"81Y", 11345},
    {"82X", 11350},
    {"82Y", 11355},
    {"83X", 11360},
    {"83Y", 11365},
    {"84X", 11370},
    {"84Y", 11375},
    {"85X", 11380},
    {"85Y", 11385},
    {"86X", 11390},
    {"86Y", 11395},
    {"87X", 11400},
    {"87Y", 11405},
    {"88X", 11410},
    {"88Y", 11415},
    {"89X", 11420},
    {"89Y", 11425},
    {"90X", 11430},
    {"90Y", 11435},
    {"91X", 11440},
    {"91Y", 11445},
    {"92X", 11450},
    {"92Y", 11455},
    {"93X", 11460},
    {"93Y", 11465},
    {"94X", 11470},
    {"94Y", 11475},
    {"95X", 11480},
    {"95Y", 11485},
    {"96X", 11490},
    {"96Y", 11495},
    {"97X", 11500},
    {"97Y", 11505},
    {"98X", 11510},
    {"98Y", 11515},
    {"99X", 11520},
    {"99Y", 11525},
    {"100X", 11530},
    {"100Y", 11535},
    {"101X", 11540},
    {"101Y", 11545},
    {"102X", 11550},
    {"102Y", 11555},
    {"103X", 11560},
    {"103Y", 11565},
    {"104X", 11570},
    {"104Y", 11575},
    {"105X", 11580},
    {"105Y", 11585},
    {"106X", 11590},
    {"106Y", 11595},
    {"107X", 11600},
    {"107Y", 11605},
    {"108X", 11610},
    {"108Y", 11615},
    {"109X", 11620},
    {"109Y", 11625},
    {"110X", 11630},
    {"110Y", 11635},
    {"111X", 11640},
    {"111Y", 11645},
    {"112X", 11650},
    {"112Y", 11655},
    {"113X", 11660},
    {"113Y", 11665},
    {"114X", 11670},
    {"114Y", 11675},
    {"115X", 11680},
    {"115Y", 11685},
    {"116X", 11690},
    {"116Y", 11695},
    {"117X", 11700},
    {"117Y", 11705},
    {"118X", 11710},
    {"118Y", 11715},
    {"119X", 11720},
    {"119Y", 11725},
    {"120X", 11730},
    {"120Y", 11735},
    {"121X", 11740},
    {"121Y", 11745},
    {"122X", 11750},
    {"122Y", 11755},
    {"123X", 11760},
    {"123Y", 11765},
    {"124X", 11770},
    {"124Y", 11775},
    {"125X", 11780},
    {"125Y", 11785},
    {"126X", 11790},
    {"126Y", 11795}
  });

int frequencyForTacanChannel(const QString& channel)
{
  QString chan(channel.toUpper().simplified());

  while(!chan.isEmpty() && chan.startsWith("0"))
    chan = chan.mid(1);
  return CHANNEL_DME_FREQUENCY_MAP.value(chan, 0);
}

} // namespace util
} // namespace fs
} // namespace atools