/*
    OpenSR - opensource multi-genre game based upon "Space Rangers 2: Dominators"
    Copyright (C) 2011 - 2012 Kosyak <ObKo@mail.ru>

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

#include "Types.h"
#include "Texture.h"

namespace Rangers
{
Vector::Vector()
{
    x = 0;
    y = 0;
}

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}

Rect::Rect()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

Rect::Rect(float x1, float y1, float x2, float y2): x1(x1), y1(y1), x2(x2), y2(y2)
{
}

Rect& Rect::operator+=(const Rect& other)
{
    if (other.x2 > x2)
        x2 = other.x2;
    if (other.y2 > y2)
        y2 = other.y2;
    if (other.x1 < x1)
        x1 = other.x1;
    if (other.y1 < y1)
        y1 = other.y1;
    return *this;
}

Rect operator+(const Rect& r1, const Rect& r2)
{
    Rect result(r1);
    result += r2;
    return result;
}

bool Rect::contains(const Vector& v)
{
    return (v.x > x1) && (v.x < x2) && (v.y > y1) && (v.y < y2);
}

TextureRegion::TextureRegion(boost::shared_ptr<Texture> texture, float x, float y, float width, float height)
{
    this->texture = texture;
    if (texture)
    {
        this->u1 = float(x) / texture->width();
        this->u2 = float(x + width) / texture->width();
        this->v1 = float(y) / texture->height();
        this->v2 = float(y + height) / texture->height();
    }
    else
    {
        this->u1 = 0;
        this->u2 = 0;
        this->v1 = 0;
        this->v2 = 0;
    }
}

TextureRegion::TextureRegion(boost::shared_ptr<Texture> texture)
{
    this->texture = texture;
    if (texture)
    {
        this->u1 = 0.0f;
        this->u2 = 1.0f;
        this->v1 = 0.0f;
        this->v2 = 1.0f;
    }
    else
    {
        this->u1 = 0.0f;
        this->u2 = 0.0f;
        this->v1 = 0.0f;
        this->v2 = 0.0f;
    }
}

TextureRegion::TextureRegion()
{
    this->texture = boost::shared_ptr<Texture>();
    this->u1 = 0;
    this->u2 = 0;
    this->v1 = 0;
    this->v2 = 0;
}
}
