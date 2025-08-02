#ifndef _MA_LISTE_CHAINE_H_
#define _MA_LISTE_CHAINE_H_

struct Noeud {
    int valeur;
    int pos;
    Noeud *suivant;
    Noeud(int val);
};

class Liste {
    private:
        Noeud *m_racine;
        int taille;
    public:
        Liste();
        Liste(int racine);
};

#endif
