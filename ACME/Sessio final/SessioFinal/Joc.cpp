#include "Joc.h"
#include <iostream>
#include "Baralla.h"
#include "Jugador.h"
#include "Tauler.h"
#include "PilaCartes.h"

Joc::Joc()
{
    llavor = 0;
    a_nNumTorn = 0;
    ultimTorn = false;
    voltesUltimTorn = 0;
}

Joc::Joc(int ll)
{
    llavor = ll;
    a_nNumTorn = 0;
    ultimTorn = false;
    voltesUltimTorn = 0;
}

void Joc::afegirJugador(int nJugadors)
{
    string nomJugador;
    a_nJugadors = nJugadors;
    a_nNumTorn = 0;
    cin.ignore();
    for (int  i = 1; i <= nJugadors; i++ )
    {
        cout << "ENTRA EL NOM DEL JUGADOR " << i << ":" << endl;
        getline(cin, nomJugador);
        a_tJugadors[i - 1] = Jugador(nomJugador);
    }
}

void Joc::pasarTorn()
{
    a_nNumTorn++;

    if (a_nNumTorn >= a_nJugadors)
    {
        a_nNumTorn = 0;
    }
}

Jugador Joc::tornActual()
{
    return a_tJugadors[a_nNumTorn];
}

void Joc::mostrarTauler()
{

    if (pilaEsquerra.buida() && pilaDreta.buida())
    {
        a_tauler.mostrar(Carta(' ', ' ', 0), Carta(' ', ' ', 0));

    }
    else if (pilaEsquerra.buida())
    {
        a_tauler.mostrar(Carta(' ', ' ', 0), pilaDreta.cim());

    }
    else if (pilaDreta.buida())
    {
        a_tauler.mostrar(pilaEsquerra.cim(), Carta(' ', ' ', 0));

    }
    else
    {
        a_tauler.mostrar(pilaEsquerra.cim(), pilaDreta.cim());

    }
}

bool Joc::numJugadorsValids(int n)
{
    if (n > 0 && n <= a_nJugadors)
    {
        return true;

    }
    else
    {
        return false;
    }
}

bool Joc::comprobarMaximCartes(int maxim)
{
    return a_tJugadors[a_nNumTorn].comprobarMaxim(maxim);
}

bool Joc::comprobarPosicioTauler(int fila, int columna)
{
    return a_tauler.posicioValidaTauler(fila, columna);
}

bool Joc::comprobarPosicioTaulerBuit(int fila, int columna)
{
    return a_tauler.posicioBuida(fila, columna);
}

void Joc::mostrarMansOponents()
{
    cout << "\nMANS DELS OPONENTS:" << endl;
    for (int i = 0; i < a_nJugadors; i++)
    {
        if (i != a_nNumTorn)
        {
            a_tJugadors[i].mostrarEnFila();
            cout << " " << i + 1 << " " << a_tJugadors[i].getNom() << endl;
        }

    }
}

char Joc::pilaBuida()
{
    if (pilaEsquerra.buida())
    {
        return 'd';

    }
    else if (pilaDreta.buida())
    {
        return 'e';

    }
    else
    {
        return 'f';
    }
}

void Joc::comprobarPiles()
{
    cout << "\nPILA ESQUERRA:" << endl;
    if (!pilaEsquerra.buida())
    {
        pilaEsquerra.mostrar(2);

    }
    else
    {
        cout << "NO HI HA CAP CARTA" << endl;
    }

    cout << "\nPILA DRETA:" << endl;
    if (!pilaDreta.buida())
    {
        pilaDreta.mostrar(2);

    }
    else
    {
        cout << "NO HI HA CAP CARTA" << endl;
    }
}

void Joc::mostrarTotsSeguidors()
{

    cout << "\nTOTS ELS SEGUIDORS:" << endl;

    for (int i = 0; i < a_nJugadors; i++)
    {
        cout << i + 1 << " " << a_tJugadors[i].getNom() << endl;
        cout << " ";
        a_tJugadors[i].mostrarSeguidors(1);
        cout << endl;
    }


}

void Joc::mostrarSeguidors(bool ultimo)
{

    if (!ultimo)
    {
        cout << "\nRESUM DELS SEGUIDORS:" << endl;

        a_tJugadors[a_nNumTorn].mostrarSeguidors(2);
        cout << " " << a_nNumTorn + 1 << " " << a_tJugadors[a_nNumTorn].getNom() << endl;

        for (int i = 0; i < a_nJugadors; i++)
        {
            if (i != a_nNumTorn)
            {
                a_tJugadors[i].mostrarSeguidors(2);
                cout << " " << i + 1 << " " << a_tJugadors[i].getNom() << endl;
            }

        }

    }
    else
    {
        cout << "\nRESUM DELS SEGUIDORS:" << endl;

        for (int i = 0; i < a_nJugadors; i++)
        {

            a_tJugadors[i].mostrarSeguidors(2);
            cout << " " << i + 1 << " " << a_tJugadors[i].getNom() << endl;


        }
    }

}

void Joc::calcularPuntuacio()
{
    bool dentro = true;
    int puntuacioAlta;
    int numMag = a_b.getNumMagies();

    char *a_taulaMagies = new char[6];
    a_taulaMagies[0] = 'b';
    a_taulaMagies[1] = 'o';
    a_taulaMagies[2] = 'p';
    a_taulaMagies[3] = 'r';
    a_taulaMagies[4] = 't';
    a_taulaMagies[5] = 'v';


    for (int i = 0; i < numMag; i++)
    {

        puntuacioAlta = 0;
        for (int j = 0; j < a_nJugadors; j++)
        {
            if (a_tJugadors[j].calcularMagiaMesAlta(a_taulaMagies[i]) > puntuacioAlta)
            {
                puntuacioAlta = a_tJugadors[j].calcularMagiaMesAlta(a_taulaMagies[i]);

            }

        }


        for (int o = 0; o < a_nJugadors; o++)
        {
            a_tJugadors[o].controlaMagia(a_taulaMagies[i], puntuacioAlta);

        }


    }

    cout << "\nPUNTS DE DECEPCIO:" << endl;
    int puntuacioMesBaixa;
    string nom;

    puntuacioMesBaixa = a_tJugadors[0].obtenirDecepcio();
    nom = a_tJugadors[0].getNom();
    cout << " " << puntuacioMesBaixa << " " << a_tJugadors[0].getNom() << endl;

    for (int i = 1; i < a_nJugadors; i++)
    {
        cout << " " << a_tJugadors[i].obtenirDecepcio() << " " << a_tJugadors[i].getNom() << endl;

        if (a_tJugadors[i].obtenirDecepcio() < puntuacioMesBaixa)
        {
            nom = a_tJugadors[i].getNom();
        }
    }

    cout << "\nENHORABONA " << nom << "! HAS GUANYAT LA PARTIDA!" << endl;



}

void Joc::preparar()
{
    pilaEsquerra = PilaCartes();
    pilaDreta = PilaCartes();
    a_tauler = Tauler();
    Baralla a_b = Baralla(llavor);
    a_b.barrejar();
    a_n = a_b.getNumMagies() * maximJugadors + a_b.getNumMagies() * (maximJugadors - a_nJugadors);

    for (int i = 0; i < a_n; i++)
    {
        a_b.robarCarta();
    }

    for (int i = 0; i < a_nJugadors; i++)
    {

        for (int j = 0; j < a_tJugadors[i].getNumMa(); j++)
        {
            a_tJugadors[i].afegir(a_b.robarCarta());
        }

    }

    for (int i = 0; i < cartesTauler; i++)
    {
        a_tauler.afegirCarta(a_b.robarCarta());
    }

    a_b.afegirCartaPila(pilaEsquerra, pilaDreta);

}

void Joc::ferJugada(Carta c, int fila, int columna)
{

    int comptadorInfluencia = c.getInfluencia();
    int i, finsEsquerra, finsDreta, finsAsota, finsDamunt;
    int seguidorsAconseguits = 0;
    bool dentro = true;
    bool sobrecarga = false;


    //COMPROBAMOS CUANTOS ESPACIOS QUEDAN PARA VER SI SE PROVOCA SOBRECARGA MAGICA
    if (a_tauler.comptarBuides() == 1)
    {
        sobrecarga = true;
        //cout << "SOBRECARGA TRUEEEE" << endl;

    }


    //AFEGIM LA CARTA AL TAULER
    a_tauler.afegirCartaPosicio(c, fila, columna, false);


    //COMPROBAMOS IZQUIERDA FILA
    i = columna - 1;
    finsEsquerra = columna;

    while (i >= 0 && dentro)
    {
        if (!a_tauler.posicioBuida(fila, i))
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(fila, i).getInfluencia();
            finsEsquerra = i;
        }
        else
        {
            dentro = false;
        }

        i--;

    }


    //COMPROBAMOS DERECHA FILA
    dentro = true;
    i = columna + 1;
    finsDreta = columna;

    while (i < a_tauler.getColumnes() && dentro)
    {
        if (!a_tauler.posicioBuida(fila, i))
        {
            //cout << "ENTRAAAAAAAA" << endl;
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(fila, i).getInfluencia();
            finsDreta = i;

        }
        else
        {
            dentro = false;
        }

        i++;

    }

    //cout << "AFASFASFA " << comptadorInfluencia << endl;

    //AGAFEM SEGUIDORS FILA
    if (comptadorInfluencia >= 10)
    {
        for (int i = finsEsquerra; i <= finsDreta; i++)
        {
            //cout << "ENTRA EN EL FOR " << i << endl;
            if (a_tauler.agafarCarta(fila, i).coincideixMagiaGermandat(c) && !a_tauler.agafarCarta(fila, i).esCopia(c))
            {
                //cout << "AGAFA SEGUIDORSSSSS" << endl;
                a_tJugadors[a_nNumTorn].afegirSeguidor(a_tauler.agafarCarta(fila, i));
                a_tauler.afegirCartaPosicio(Carta(' ', ' ', 0), fila, i, true);
                seguidorsAconseguits++;

            }
        }
    }


    //COMPROBAMOS ARRIBA COLUMNA
    dentro = true;
    comptadorInfluencia = c.getInfluencia();
    //cout << "\nCOMPTADOR INFLUENCIA " << comptadorInfluencia << endl;
    i = fila - 1;
    finsDamunt = fila;

    while (i >= 0 && dentro)
    {
        if (!a_tauler.posicioBuida(i, columna))
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(i, columna).getInfluencia();
            finsDamunt = i;
        }
        else
        {
            dentro = false;
        }

        i--;

    }

    //cout << "\nCOMPTADOR INFLUENCIA ARRIBA " << comptadorInfluencia << endl;

    //COMPROBAMOS ABAJO COLUMNA
    dentro = true;
    i = fila + 1;
    finsAsota = fila;

    while (i < a_tauler.getFilas() && dentro)
    {
        if (!a_tauler.posicioBuida(i, columna) )
        {
            comptadorInfluencia = comptadorInfluencia + a_tauler.agafarCarta(i, columna).getInfluencia();
            finsAsota = i;

        }
        else
        {
            dentro = false;
        }

        i++;

    }

    //cout << "\nCOMPTADOR INFLUENCIA ABAJO " << comptadorInfluencia << endl;

    //AGAFEM SEGUIDORS COLUMNA
    if (comptadorInfluencia >= 10)
    {
        for (int i = finsDamunt; i <= finsAsota; i++)
        {
            //cout << "ENTRA EN EL FOR " << i << endl;
            if (a_tauler.agafarCarta(i, columna).coincideixMagiaGermandat(c) && !a_tauler.agafarCarta(i, columna).esCopia(c))
            {
                a_tJugadors[a_nNumTorn].afegirSeguidor(a_tauler.agafarCarta(i, columna));
                a_tauler.afegirCartaPosicio(Carta(' ', ' ', 0), i, columna, true);
                seguidorsAconseguits++;

            }
        }
    }

    //cout << "SEGUIDORS ACONSEGUITS: " << seguidorsAconseguits << endl;

    //PASEM PER LA SOBRECARGA
    if (sobrecarga && seguidorsAconseguits == 0)
    {
        //cout << "ENTRA SOBRECARGA" << endl;
        for (int i = 0; i < a_tauler.getColumnes(); i++)
        {
            //cout << "ENTRA EN EL FOR DE SOBRECARGA: " << i << endl;
            if (!a_tauler.agafarCarta(fila, i).coincideixGermandat(c))
            {
                //cout << "AGAFA EL SEGUIDOR QUE NO ES DE LA MATEIXA GERMANDAT" << endl;
                a_tJugadors[a_nNumTorn].afegirSeguidor(a_tauler.agafarCarta(fila, i));
                a_tauler.afegirCartaPosicio(Carta(' ', ' ', 0), fila, i, true);

            }
        }

        for (int i = 0; i < a_tauler.getFilas(); i++)
        {
            if (!a_tauler.agafarCarta(i, columna).coincideixGermandat(c))
            {
                a_tJugadors[a_nNumTorn].afegirSeguidor(a_tauler.agafarCarta(i, columna));
                a_tauler.afegirCartaPosicio(Carta(' ', ' ', 0), i, columna, true);

            }
        }
    }

}

void Joc::omplirTaulerBruixots(PilaCartes& p, PilaCartes& pAux)
{
    int llocsBuits = a_tauler.comptarBuides();
    for (int i = 4; i < llocsBuits; i++)
    {
        if (!p.buida())
        {
            a_tauler.omplirEspaisBuits(p.cim());
            p.desempila();

        }
        else if (!pAux.buida())
        {
            a_tauler.omplirEspaisBuits(pAux.cim());
            pAux.desempila();
        }
    }

}

bool Joc::permetTorn()
{
    if (ultimTorn && a_tJugadors[a_nNumTorn].maPlena() || !ultimTorn)
    {
        return true;

    }
    else
    {
        return false;
    }

}

bool Joc::ultimaVoltaCompletada()
{
    if (voltesUltimTorn == a_nJugadors)
    {
        return true;

    }
    else
    {
        return false;
    }
}

void Joc::posarInfluencia()
{
    for (int i = 0; i < a_nJugadors; i++)
    {
        a_tJugadors[i].pasarMaASeguidors();
    }
}

void Joc::jugarSenseInfluencia(int posicio, int fila, int columna, char pila)
{

    bool pilasBuidas = false;

    if (tornActual().posicioCartaValid(posicio))
    {
        if (a_tauler.posicioValidaTauler(fila, columna))
        {
            if (pila == 'e' || pila == 'd')
            {
                Carta cartaAux = tornActual().agafarCarta(posicio);

                if (!ultimTorn)
                {

                    if (pila == 'e')
                    {

                        if (!pilaEsquerra.buida())
                        {

                            a_tJugadors[a_nNumTorn].afegirCartaPosicio(pilaEsquerra.cim(), posicio);
                            pilaEsquerra.desempila();


                        }
                        else if (!pilaDreta.buida())
                        {

                            a_tJugadors[a_nNumTorn].afegirCartaPosicio(pilaDreta.cim(), posicio);
                            pilaDreta.desempila();

                        }
                        else
                        {
                            ultimTorn = true;
                        }



                    }
                    else
                    {

                        if (!pilaDreta.buida())
                        {

                            a_tJugadors[a_nNumTorn].afegirCartaPosicio(pilaDreta.cim(), posicio);
                            pilaDreta.desempila();

                        }
                        else if (!pilaEsquerra.buida())
                        {

                            a_tJugadors[a_nNumTorn].afegirCartaPosicio(pilaEsquerra.cim(), posicio);
                            pilaEsquerra.desempila();

                        }
                        else
                        {
                            ultimTorn = true;
                        }

                    }

                }
                else
                {
                    a_tJugadors[a_nNumTorn].afegirCartaPosicio(Carta(' ', ' ', 0), posicio);
                    voltesUltimTorn++;
                }


                ferJugada(cartaAux, fila, columna);


                if (a_tauler.comptarBuides() > 4 && !ultimTorn)
                {
                    if (pila == 'e')
                    {
                        if (!pilaEsquerra.buida())
                        {
                            omplirTaulerBruixots(pilaEsquerra, pilaDreta);

                        }
                        else if (!pilaDreta.buida())
                        {
                            omplirTaulerBruixots(pilaDreta, pilaEsquerra);

                        }
                        else
                        {
                            ultimTorn = true;
                        }


                    }
                    else
                    {
                        if (!pilaDreta.buida())
                        {
                            omplirTaulerBruixots(pilaDreta, pilaEsquerra);

                        }
                        else if (!pilaEsquerra.buida())
                        {
                            omplirTaulerBruixots(pilaEsquerra, pilaDreta);

                        }
                        else
                        {
                            ultimTorn = true;
                        }
                    }
                }

            }
            else
            {
                cout << "PILA NO VALIDA" << endl;
            }

        }
        else
        {
            cout << "LA POSICIO DEL TAULER NO ES VALIDA" << endl;

        }

    }
    else
    {
        cout << "NO HI HA CARTAS A AQUESTA POSICIO" << endl;

    }
}

bool Joc::jugarAmbInfluencia(char magia, int jugadorEscollit)
{
    if (jugadorEscollit < 0 || jugadorEscollit >= a_nJugadors)
    {
        return false;
    }

    if(a_tJugadors[a_nNumTorn].donarSeguidors(a_tJugadors[jugadorEscollit], magia))
    {
        return true;

    }
    else
    {
        return false;
    }
}
