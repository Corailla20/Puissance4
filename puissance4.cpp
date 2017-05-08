#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkMinimalStandardRandomSequence.h>

#include "puissance4.h"

int main()
{
	vtkSmartPointer<vtkActor> tableau[7][6];

	// Sphere source
	/*vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
	sphereSource->SetCenter(0.0, 0.0, 0.0);
	sphereSource->SetRadius(1.0);*/

	// Cylinder source : création de la taille des jetons
	vtkSmartPointer<vtkCylinderSource> cylinderSource =
    vtkSmartPointer<vtkCylinderSource>::New();
	cylinderSource->SetCenter(0.0, 1.0, 0.0);
	cylinderSource->SetRadius(1.0);
	cylinderSource->SetHeight(0.5);
	cylinderSource->SetResolution(100);

	// PolyDataMapper
	vtkSmartPointer<vtkPolyDataMapper> polyDataMapper = 
		vtkSmartPointer<vtkPolyDataMapper>::New();
	polyDataMapper->SetInputConnection(cylinderSource->GetOutputPort());



	// Renderer
	vtkSmartPointer<vtkRenderer> renderer = 
		vtkSmartPointer<vtkRenderer>::New();
	renderer->SetBackground(0.1, 0.2, 0.4);

	double yspacing = 2.0, zspacing = 2.0;
	
	// Création de la grille : Création des jetons, définition de leur position et ajout au renderer
	for (int j=0; j<7; j++)
	{
		double y = yspacing * j;
		for (int k=0; k<6; k++)
		{
			double z = zspacing * k;

			vtkSmartPointer<vtkActor> actor = 
				vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(polyDataMapper);
			actor->SetPosition(y, z, 0);
			
			vtkSmartPointer<vtkProperty> colorProperty = 
				vtkSmartPointer<vtkProperty>::New();
			colorProperty->SetColor(0,0,0);
			
			actor->SetProperty(colorProperty);
			actor->RotateX(90);
			
			renderer->AddActor(actor);
			tableau[j][k] = actor;
		}
	}

	// Texte (en bas à gauche) pour aider les joueurs
	vtkSmartPointer<vtkTextActor> textActor =  vtkSmartPointer<vtkTextActor>::New();
	textActor->SetInput ("Press i to init game\nPress 1 to 7 to put a stone");
	textActor->SetPosition2 (50, 40);
	textActor->GetTextProperty()->SetFontSize(24);
	renderer->AddActor2D (textActor);

	//Texte de victoire	
	vtkSmartPointer<vtkTextActor> textVictoire = 
		vtkSmartPointer<vtkTextActor>::New();
    textVictoire->SetDisplayPosition(250, 650);
	textVictoire->GetTextProperty()->SetFontSize(50);
	renderer->AddActor2D(textVictoire);

	// Render window
	vtkSmartPointer<vtkRenderWindow> renderWindow = 
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	renderWindow->SetSize(1000, 750);

	// Render window interactor
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	// Création d'un nouvel Observer 
	vtkSmartPointer<Observer> observer =
		vtkSmartPointer<Observer>::New();
	observer->SetRenderWindowInteractor(renderWindowInteractor);
	observer->SetTextActorVictoire(textVictoire);
	observer->SetTableau(tableau);
	renderWindowInteractor->AddObserver(
		vtkCommand::KeyPressEvent,observer);

	renderWindow->Render();
	renderWindowInteractor->Start();

	return 0;
}