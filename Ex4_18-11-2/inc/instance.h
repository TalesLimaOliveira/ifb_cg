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
};

#endif//INSTANCE_H
