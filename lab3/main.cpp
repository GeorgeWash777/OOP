#include "include/Triangle.h"
#include "include/Hexagon.h"
#include "include/Octagon.h"
#include <memory>

using namespace std;

int main()
{
  vector<shared_ptr<Figure>> figures;

  while (true)
  {
    cout << "\nМеню:\n";
    cout << "1. Добавить треугольник\n";
    cout << "2. Добавить шестиугольник(гексагон)\n";
    cout << "3. Добавить восьмиугольник(октагон ММА аххах)\n";
    cout << "4. Вывести все фигуры\n";
    cout << "5. Вывести центры всех фигур\n";
    cout << "6. Вывести площади всех фигур\n";
    cout << "7. Вывести общую площадь\n";
    cout << "8. Удалить фигуру по индексу\n";
    cout << "9. Выйди отсюда\n";
    cout << "Выбери опцию: ";

    int option;
    cin >> option;

    switch (option)
      {
      case 1:
      {
        auto fig = make_shared<Triangle>();
        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 2:
      {
        auto fig = make_shared<Hexagon>();
        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 3:
      {
        auto fig = make_shared<Octagon>();
        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 4:
      {
        for (size_t i = 0; i < figures.size(); ++i)
        {
          cout << i << ": " << *figures[i] << endl;
        }
        break;
      }
      case 5:
      {
        for (size_t i = 0; i < figures.size(); ++i)
        {
          auto center = figures[i]->Center();
          cout << i << ": Центр в (" << center.first << ", " << center.second << ")\n";
        }
        break;
      }
      case 6:
      {
        for (size_t i = 0; i < figures.size(); ++i)
        {
          double area = static_cast<double>(*figures[i]);
          cout << i << ": Площадь = " << area << "\n";
        }
        break;
      }
      case 7:
      {
        double total_area = 0;
        for (const auto &fig : figures)
        {
          total_area += static_cast<double>(*fig);
        }
        cout << "Общая площадь всех фигур: " << total_area << "\n";
        break;
      }
      case 8:
      {
        cout << "Введите индекс для удаления фигуры: ";
        size_t index;
        cin >> index;
        if (index < figures.size())
        {
          figures.erase(figures.begin() + index);
          cout << "Фигура с индексом " << index << " удалена\n";
        }
        else
        {
          cout << "Такой фигуры нет\n";
        }
        break;
      }
      case 9:
      {
        return 0;
      }
      default:
      {
        cout << "Осьминогов в меню нет\n";
        break;
      }
    }
  }

  return 0;
}