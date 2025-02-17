#include <iostream>
#include "include/point.h"
#include "include/array.h"

#include "include/hexagon.h"
#include "include/octagon.h"
#include "include/triangle.h"


using namespace std;

int main() 
{
    Array<Figure<int>> figureCollection;

    while (true) 
    {
        cout << "Меню:\n";
        cout << "1. Добавить фигуру\n";
        cout << "2. Удалить фигуру\n";
        cout << "3. Показать все фигуры\n";
        cout << "4. Посчитать общую площадь\n";
        cout << "5. Выйти\n";
        
        int userChoice;
        cin >> userChoice;

        switch (userChoice) 
        {
            case 1: 
            {
                cout << "Выбери тип фигуры:\n";
                cout << "1. Шестиугольник(гексагон)\n";
                cout << "2. Восьмиугольник(ОКТАГОН ХАХААХ ММА ЧТО ЛИ?)\n";
                cout << "3. Треугольник\n";
                
                int figureType;
                cin >> figureType;

                shared_ptr<Figure<int>> newFigure;

                switch (figureType) 
                {
                    case 1:
                        newFigure = make_shared<Hexagon<int>>();
                        break;
                    case 2:
                        newFigure = make_shared<Octagon<int>>();
                        break;
                    case 3:
                        newFigure = make_shared<Triangle<int>>();
                        break;
                    default:
                        cout << "Ты че вводишь, чувак?\n";
                        continue;
                }

                cin >> *newFigure;
                figureCollection.push_back(newFigure);
                break;
            }
            case 2: 
            {
                cout << "Введите индекс фигуры, которую хотите удалить ";
                size_t indexToRemove;
                cin >> indexToRemove;

                if (indexToRemove >= figureCollection.get_size()) 
                {
                    cout << "Ты че вводишь, чувак?\n";
                } 
                else 
                {
                    figureCollection.remove_at(indexToRemove);
                    cout << "Минус фигура\n";
                }
                break;
            }
            case 3: 
            {
                for (size_t i = 0; i < figureCollection.get_size(); ++i) 
                {
                    cout << "Фигура " << i << ":\n";
                    cout << *figureCollection[i];
                    
                    auto center = figureCollection[i]->Center();
                    cout << "Центр фигуры: " << *center << endl;
                    
                    double area = *figureCollection[i];
                    cout << "Площадь фигуры: " << area << endl;
                    cout << "==ДОБРО И ПОЗИТИВ==\n";
                }
                break;
            }
            case 4: 
            {
                double totalArea = 0.0;
                for (size_t i = 0; i < figureCollection.get_size(); ++i) 
                {
                    totalArea += static_cast<double>(*figureCollection[i]);
                }
                cout << "Общая площадь всех фигур: " << totalArea << endl;
                break;
            }
            case 5: 
            {
                return 0;
            }
            default: 
            {
                cout << "Ты че вводишь, чувак?\n";
                break;
            }
        }
    }

    return 0;
}