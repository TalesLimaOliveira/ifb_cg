#include "instance.h"

Instancia::Instancia(void) {
    ex = ey = 1;
    tx = ty = 0;
    angulo = 0;
}

double Instancia::getTx(void) {
    return tx;
}

double Instancia::getTy(void) {
    return ty;
}

double Instancia::getEx(void) {
    return ex;
}

double Instancia::getEy(void) {
    return ey;
}

double Instancia::getAngulo(void) {
    return angulo;
}

void Instancia::incrementaAngulo() {
    angulo += 1;
}

void Instancia::decrementaAngulo() {
    angulo -= 1;
}

void Instancia::incrementaTx() {
    tx += 1;
}

void Instancia::incrementaTy() {
    ty += 1;
}

void Instancia::incrementaEx() {
    ex += 1;
}

void Instancia::incrementaEy() {
    ey += 1;
}

void Instancia::decrementaTx() {
    tx -= 1;
}

void Instancia::decrementaTy() {
    ty -= 1;
}

void Instancia::decrementaEx() {
    ex -= 1;
}

void Instancia::decrementaEy() {
    ey -= 1;
}