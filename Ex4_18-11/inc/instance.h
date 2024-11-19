#ifndef INSTANCE_H
#define INSTANCE_H

class Instancia{
    public:
        Instancia(void);
        double getTx(void);
        double getTy(void);
        double getEx(void);
        double getEy(void);
        double getAngulo(void);
        void incrementaAngulo();
        void decrementaAngulo();
        void incrementaTx();
        void incrementaTy();
        void incrementaEx();
        void incrementaEy();
        void decrementaTx();
        void decrementaTy();
        void decrementaEx();
        void decrementaEy();

    private:
        double tx, ty;
        double ex, ey;
        double angulo;
    

    Instancia::Instancia(void){
        ex = ey = 1;
        tx = ty = 0;
        angulo =0;
    }

    inline double Instancia::getTx(void){
        return tx;
    }

    inline double Instancia::getTy(void){
        return ty;
    }

    inline double Instancia::getEx(void){
        return ex;
    }

    inline double Instancia::getEy(void){
        return ey;
    }

    inline double Instancia::getAngulo(void){
        return angulo;
    }

    void Instancia::incrementaAngulo() {
        angulo += 1;
    }

    void Instancia::decrementaAngulo(){
        angulo -= 1;
    }

    inline void Instancia::incrementaTx(){
        tx += 0.1;
    }

    inline void Instancia::incrementaTy(){
        ty += 0.1;
    }

    inline void Instancia::incrementaEx(){
        ex += 0.1;
    }

    inline void Instancia::incrementaEy(){
        ey += 0.1;
    }

    inline void Instancia::decrementaTx(){
        tx -= 0.1;
    }

    inline void Instancia::decrementaTy(){
        ty -= 0.1;
    }

    inline void Instancia::decrementaEx(){
        ex -= 0.1;
    }

    inline void Instancia::decrementaEy(){
        ey -= 0.1;
    }
};

#endif//INSTANCE_H
