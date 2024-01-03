#include <stdio.h>
#include <stdbool.h>

// Déclaration des fonctions
int obtenirNombreDecimal();
void initialiserTableau(char tableau[], int taille);
void remplirTableauMessage(char tableau[], int taille);
void afficherTableau(char tableau[], int taille);
int demanderCle();
int determinerPosition(char lettre);
void chiffrerMessage(char message[], char chiffre[], int cle);
void dechiffrerMessage(char dechiffre[], char chiffre[], int cle);

// Déclaration des constantes
#define ALPHABET_LENGTH 26
const char ALPHABET[ALPHABET_LENGTH] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int longueurChaine; // Vous pouvez déplacer la déclaration ici

int main()
{
    // Déclaration et initialisation des variables
    char message[longueurChaine];
    char chiffre[longueurChaine];
    char dechiffre[longueurChaine];
    int cle = -1;

    // Utilisation de la fonction pour obtenir un nombre décimal
    longueurChaine = obtenirNombreDecimal();

    // Affichage de la valeur obtenue
    printf("Vous avez saisi : %d\n", longueurChaine);

    // Initialisation des tableaux
    initialiserTableau(message, longueurChaine);
    initialiserTableau(chiffre, longueurChaine);
    initialiserTableau(dechiffre, longueurChaine);

    // Remplir le tableau message en demandant à l'utilisateur
    remplirTableauMessage(message, longueurChaine);

    // Affichage du message initial
    afficherTableau(message, longueurChaine);

    // Demande la clé de chiffrement à l'utilisateur
    cle = demanderCle();

    // Chiffre le message
    chiffrerMessage(message, chiffre, cle);

    // Affichage du message chiffré
    afficherTableau(chiffre, longueurChaine);

    // Déchiffre le message
    dechiffrerMessage(dechiffre, chiffre, cle);

    // Affichage du message déchiffré
    afficherTableau(dechiffre, longueurChaine);

    return 0;
}

// Implémentation des fonctions

// Fonction pour obtenir un nombre décimal de l'utilisateur
int obtenirNombreDecimal()
{
    int nombre;

    printf("Entrez un nombre décimal : ");
    while (scanf("%d", &nombre) != 1)
    {
        // Si la saisie n'est pas un nombre, vider le tampon d'entrée et demander à nouveau
        printf("Entrée non valide. Veuillez entrer un nombre décimal : ");
        while (getchar() != '\n'); // Vider le tampon d'entrée
    }

    return nombre;
}

void initialiserTableau(char tableau[], int taille)
{
    // Parcours le tableau
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = ' ';
    }
}

void remplirTableauMessage(char tableau[], int taille)
{
    // Parcours le tableau
    for (int i = 0; i < taille; i++)
    {
        // Booléen permettant de contrôler la validité de la saisie utilisateur
        bool valide = false;
        do {
            printf("Veuillez saisir un caractère en MAJUSCULE entre A et Z : ");
            scanf(" %c", &tableau[i]);
            for (int j = 0; j < ALPHABET_LENGTH; j++)
            {
                if (tableau[i] == ALPHABET[j])
                {
                    valide = true;
                }
            }
        } while (!valide);
    }
}

void afficherTableau(char tableau[], int taille)
{
    // Parcours le tableau
    for (int i = 0; i < taille; i++)
    {
        // Affiche l'élément du tableau et ajoute un séparateur entre les éléments
        printf("%c | ", tableau[i]);
    }
    printf("\n");
}

int demanderCle()
{
    int cle = -2;
    do {
        // Lecture et récupération de l'entrée utilisateur
        printf("Veuillez saisir votre clé : ");
        scanf("%d", &cle);
    } while (cle < 1 || cle > 25);

    return cle;
}

int determinerPosition(char lettre)
{
    int position = -1;

    // On parcourt tout le tableau alphabet
    for (int j = 0; j < ALPHABET_LENGTH; j++)
    {
        // Quand les deux lettres sont égales, on récupère le rang
        if (lettre == ALPHABET[j])
        {
            position = j;
        }
    }
    return position;
}

void chiffrerMessage(char message[], char chiffre[], int cle)
{
    int position = -1;
    int decalage = -1;

    for (int i = 0; i < longueurChaine; i++)
    {
        position = determinerPosition(message[i]);

        // Si le rang de la lettre à chiffrer plus la clé est supérieur à 26,
        // on soustrait 26 pour rester dans le tableau alphabet
        if ((position + cle) > (ALPHABET_LENGTH - 1))
        {
            decalage = (position + cle) - 26;
        }
        else if ((position + cle) < 0)
        {
            decalage = (position + cle) + 26;
        }
        else
        {
            decalage = position + cle;
        }
        chiffre[i] = ALPHABET[decalage];
    }
}

void dechiffrerMessage(char dechiffre[], char chiffre[], int cle)
{
    int position = -1;
    int decalage = -1;

    for (int i = 0; i < longueurChaine; i++)
    {
        position = determinerPosition(chiffre[i]);

        // Si le rang de la lettre à déchiffrer plus la clé est inférieur à 0,
        // on ajoute 26 pour rester dans le tableau alphabet
        if ((position - cle) > (ALPHABET_LENGTH - 1))
        {
            decalage = (position - cle) - 26;
        }
        else if ((position - cle) < 0)
        {
            decalage = (position - cle) + 26;
        }
        else
        {
            decalage = position - cle;
        }
        dechiffre[i] = ALPHABET[decalage];
    }
}
