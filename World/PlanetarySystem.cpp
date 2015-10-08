/*
    OpenSR - opensource multi-genre game based upon "Space Rangers 2: Dominators"
    Copyright (C) 2015 Kosyak <ObKo@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "PlanetarySystem.h"

#include <QtQml>

namespace OpenSR
{
namespace World
{
const quint32 PlanetarySystem::m_staticTypeId = typeIdFromClassName(PlanetarySystem::staticMetaObject.className());

template<>
void WorldObject::registerType<PlanetarySystem>()
{
    qRegisterMetaType<PlanetarySystemStyle>();
    qRegisterMetaTypeStreamOperators<PlanetarySystemStyle>();
    qmlRegisterType<PlanetarySystem>("OpenSR.World", 1, 0, "PlanetarySystem");
}

template<>
PlanetarySystem* WorldObject::createObject(WorldObject *parent, quint32 id)
{
    return new PlanetarySystem(parent, id);
}

template<>
quint32 WorldObject::staticTypeId<PlanetarySystem>()
{
    return PlanetarySystem::m_staticTypeId;
}

template<>
const QMetaObject* WorldObject::staticTypeMeta<PlanetarySystem>()
{
    return &PlanetarySystem::staticMetaObject;
}

PlanetarySystem::PlanetarySystem(WorldObject *parent, quint32 id): WorldObject(parent, id)
{
}

PlanetarySystem::~PlanetarySystem()
{
}

quint32 PlanetarySystem::typeId() const
{
    return PlanetarySystem::m_staticTypeId;
}

QString PlanetarySystem::namePrefix() const
{
    return tr("System");
}

QDataStream& operator<<(QDataStream & stream, const PlanetarySystemStyle & style)
{
    return stream << style.background << style.star << style.starColor;
}

QDataStream& operator>>(QDataStream & stream, PlanetarySystemStyle & style)
{
    return stream >> style.background >> style.star >> style.starColor;
}

PlanetarySystemStyle PlanetarySystem::style() const
{
    return m_style;
}

int PlanetarySystem::size() const
{
    return m_size;
}

void PlanetarySystem::setStyle(const PlanetarySystemStyle& style)
{
    m_style = style;
    emit(styleChanged());
}

void PlanetarySystem::setSize(int size)
{
    if (m_size != size)
    {
        m_size = size;
        emit(sizeChanged());
    }
}
}
}
