#include <vtkCommand.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkTextActor.h>
#include <vtkProperty.h>


class Observer : public vtkCommand {
public:	
	static Observer* New() { return new Observer; }
	void Execute(vtkObject*, unsigned long, void*)
	{
		int pion = 0;
		vtkSmartPointer<vtkProperty> colorProperty = 
				vtkSmartPointer<vtkProperty>::New();
		// Vérifie si c'est le tour du jouer 1 ou 2 et met donc la bonne couleur à la vtkProperty précedement créée (elle sera "seter" plus tard au bon jeton)
		if(tour%2 == 1)
		{			
			colorProperty->SetColor(1,0,0); // Pion rouge
			pion = 1;
			
		}
		else if(tour%2 == 0)
		{						
			colorProperty->SetColor(1,1,0); //Pion jaune
			pion = 2;
		}
		
		
		int i = 0;
		switch(renderWindowInteractor->GetKeyCode()) {
			// Vérifier si ‘i’ appuyé
			case 'i':
				//Init Game
				tour = 1;
				freeze = 0;
				textVictoire->SetInput ("");
				colorProperty->SetColor(0.05,0.05,0.05); // Pion "noir"
				for(int k = 0; k < 7; k++)
				{
					for(int j = 0; j < 6; j++)
					{
						this->tableau[k][j] = tableau[k][j];
						this->tableau[k][j]->SetProperty(colorProperty);
						this->tableau2[k][j] = 0;
					}
				}
				break;

			// Vérifier si ‘1’ appuyé
			case '1':
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[0][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[0][i]->SetProperty(colorProperty);
						this->tableau2[0][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;

			// Vérifier si ‘2’ appuyé
			case '2' :
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[1][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[1][i]->SetProperty(colorProperty);
						this->tableau2[1][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;

			// Vérifier si ‘3’ appuyé
			case '3' :
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[2][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[2][i]->SetProperty(colorProperty);
						this->tableau2[2][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;

			// Vérifier si ‘4’ appuyé
			case '4' :
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[3][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[3][i]->SetProperty(colorProperty);
						this->tableau2[3][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;	
			// Vérifier si ‘5’ appuyé
			case '5' :
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[4][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[4][i]->SetProperty(colorProperty);
						this->tableau2[4][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;
			// Vérifier si ‘6’ appuyé
			case '6' :
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[5][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[5][i]->SetProperty(colorProperty);
						this->tableau2[5][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;

			// Vérifier si ‘7’ appuyé
			case '7' :
				if(freeze == 0) {
					// vérifie dans quelle ligne de la colonne le jetons doit être placé
					while(this->tableau2[6][i] != 0)
					{
						i++;
					}
					// vérifie si la colonne n'est pas pleine puis "place le jetons" au bon endroit --> on change la couleur du jeton grâce à colorProperty.
					// incrémente le tour
					if(i < 6)
					{
						this->tableau[6][i]->SetProperty(colorProperty);
						this->tableau2[6][i] = pion;
						this->tour++;
					}
					if(verifierVictoire()) {
						if(pion == 1) {
							textVictoire->SetInput ("Victoire joueur rouge");
							textVictoire->GetTextProperty()->SetColor(1.0, 0.0, 0.0);
						}
						if(pion == 2) {					
							textVictoire->SetInput ("Victoire joueur jaune");					
							textVictoire->GetTextProperty()->SetColor(1.0, 1.0, 0.0);
						}
						freeze = 1;
					}
				}
				break;
		}
		
		this->renderWindowInteractor->Render();
	}

	// fonction setter pour le RenderWindowInteractor
	void SetRenderWindowInteractor(vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor)
	{ 
		this->renderWindowInteractor = renderWindowInteractor;
	}

	// fonction setter pour le vtkTextActor qui sert a afficher le nom du vainqueur
	void SetTextActorVictoire(vtkSmartPointer<vtkTextActor> textVictoire)
	{ 
		this->textVictoire = textVictoire;
	}


	// fonction setter pour le tableau d'acteur
	void SetTableau(vtkSmartPointer<vtkActor> tableau[7][6])
	{ 
		this->tour = 1;
		this->freeze = 0; // si partie fini, freeze = 1 --> on ne peut plus jouer de jeton
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				this->tableau[i][j] = tableau[i][j];
				this->tableau2[i][j] = 0;
			}
		}
	}

	// Fonction qui permet de verifier si un des joueurs a aligné 4 jetons verticalement, horizontalement ou en diagonale
	// Retourne 1 si 4 jetons sont alignés, sinon retourne 0
	int verifierVictoire() {
		// Vérifie les horizontales ( - )
		for (int ligne = 0; ligne < 8; ligne++) {
		  if (cherche4alignes(0, ligne, 1, 0)) {
			return 1;
		  }
		}

		// Vérifie les verticales ( ¦ )
		for (int col = 0; col < 7; col++) {
		  if (cherche4alignes(col, 0, 0, 1)) {
			return 1;
		  }
		}

		// Diagonales (cherche depuis la ligne du bas)
		for (int col = 0; col < 8; col++) {
		  // Première diagonale ( / )
		  if (cherche4alignes(col, 0, 1, 1)) {
			return 1;
		  }
		  // Deuxième diagonale ( \ )
		  if (cherche4alignes(col, 0, -1, 1)) {
			return 1;
		  }
		}

		// Diagonales (cherche depuis les colonnes gauches et droites)
		for (int ligne = 0; ligne < 8; ligne++) {
		  // Première diagonale ( / )
		  if (cherche4alignes(0, ligne, 1, 1)) {
			return 1;
		  }
		  // Deuxième diagonale ( \ )
		  if (cherche4alignes(8 - 1, ligne, -1, 1)) {
			return 1;
		  }
		}

		// On n'a rien trouvé
		return 0;
	}

	// Fonction appeler par verifierVictoire afin de regarder si 4 jetons sont alignés
	// Retourne 1 si 4 jetons sont alignés, sinon retourne 0
	int cherche4alignes(int oCol, int oLigne, int dCol, int dLigne) {
		int couleur = 0;
		int compteur = 0;

		int curCol = oCol;
		int curRow = oLigne;

		while ((curCol >= 0) && (curCol < 8) && (curRow >= 0) && (curRow < 7)) {
			if (tableau2[curRow][curCol] != couleur) {
			// Si la couleur change, on réinitialise le compteur
			couleur = tableau2[curRow][curCol];
			compteur = 1;
		  } else {
			// Sinon on l'incrémente
			compteur++;
		  }

		  // On sort lorsque le compteur atteint 4
		  if ((couleur != 0) && (compteur == 4)) {
			return 1;
		  }

		  // On passe à l'itération suivante
		  curCol += dCol;
		  curRow += dLigne;
		}

		// Aucun alignement n'a été trouvé
		return 0;
	}

protected:

private:
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
	vtkSmartPointer<vtkTextActor> textVictoire;
	vtkSmartPointer<vtkActor> tableau[7][6];
	int tableau2[7][6];
	int MinimumResolution, MaximumResolution;
	int tour;
	int freeze;
};