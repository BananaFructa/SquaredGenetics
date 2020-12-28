#pragma once

void NormalizeViewport(sf::RenderWindow* Window, float fov,sf::Vector2f CameraPosition) {
    sf::Vector2f WindowResolution = sf::Vector2f((float)Window->getSize().x, (float)Window->getSize().y);
    sf::Vector2f ViewProportion = sf::Vector2f(WindowResolution.x / fov, WindowResolution.y / fov);
    sf::View MainView = sf::View(CameraPosition, ViewProportion);
    Window->setView(MainView);
}

void DrawLine(sf::RenderWindow* Window, float x1,float y1,float x2,float y2,sf::Color Color) {
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(x1, y1);
    lines[1].position = sf::Vector2f(x2, y2);
    lines[0].color = Color;
    lines[1].color = Color;
    Window->draw(lines);
}

void DrawHollowSquare(sf::RenderWindow* Window, float x, float y, sf::Color Color) {
    sf::VertexArray lines(sf::Quads, 4);
    lines[0].position = sf::Vector2f(x+0.05f, y+0.05f);
    lines[1].position = sf::Vector2f(x+0.95f, y + 0.05f);
    lines[2].position = sf::Vector2f(x + 0.95f, y + 0.95f);
    lines[3].position = sf::Vector2f(x + 0.05f, y + 0.95f);
    lines[0].color = Color;
    lines[1].color = Color;
    lines[2].color = Color;
    lines[3].color = Color;
    Window->draw(lines);
}

int XUnitsCount(sf::RenderWindow* Window, float fov) {
    return (int)((float)Window->getSize().x / fov);
}

int YUnitsCount(sf::RenderWindow* Window, float fov) {
    return (int)((float)Window->getSize().y / fov);
}

float Fract(float f) {
    return f - (int)f;
}

float Clamp(float v, float l, float h) {
    return std::min(std::max(v, l), h);
}

void DrawGrid(sf::RenderWindow* Window, float fov) {
    int XUnits = XUnitsCount(Window,fov);
    int YUnits = YUnitsCount(Window, fov);

    // It's floored so it creates the moving effect

    for (int i = -XUnits - 1;i <= XUnits + 1;i++) {
        DrawLine(Window, i, -YUnits, i , YUnits, sf::Color::Color(25, 25, 25));
    }

    for (int j = -YUnits - 1;j <= YUnits + 1;j++) {
        DrawLine(Window, -XUnits , j , XUnits, j , sf::Color::Color(25, 25, 25));
    }
}