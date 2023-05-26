#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define EVEN 0
#define ODD 1

#define GROUND 0
#define EGG 1
#define CRYSTAL 2

class Cell
{
    public:
    int index;
    int type;
    int initial_ressources;
    int neigh_0;
    int neigh_1;
    int neigh_2;
    int neigh_3;
    int neigh_4;
    int neigh_5;
    int my_ants;
    int opp_ants;
    int distance_my_base;

    Cell(int index, int type, int initial_ressources, int neigh_0, int neigh_1, int neigh_2, int neigh_3, int neigh_4, int neigh_5, int my_ants, int opp_ants, int distance_my_base):
        index(index), type(type), initial_ressources(initial_ressources), neigh_0(neigh_0), neigh_1(neigh_1), neigh_2(neigh_2), neigh_3(neigh_3), neigh_4(neigh_4), neigh_5(neigh_5), my_ants(my_ants), opp_ants(opp_ants), distance_my_base(distance_my_base)
    {

    }
    Cell() = default;
};


int my_total_ants(std::vector<Cell> cells, int number_of_cells)
{
    int i = 0;
    int total = 0;
    while (i < number_of_cells)
    {
        total = cells[i].my_ants + total;
        i++;
    }
    return (total);
}

int his_total_ants(std::vector<Cell> cells, int number_of_cells)
{
    int i = 0;
    int total = 0;
    while (i < number_of_cells)
    {
        total += cells[i].opp_ants;
        i++;
    }
    return (total);
}


int where_is_big_egg(Cell *newcell, int nb_cells)
{
    int i = 0;
    int biggest = 0;
    while (i < nb_cells)
    {
        if (newcell[i].type == 1 && (newcell[i].initial_ressources > newcell[biggest].initial_ressources))
            biggest = i;
        i++;
    }
    return (biggest);
}

int neigh_higher(std::vector<Cell> cells, int index)
{
    int higher = 0;
    if (cells[cells[index].neigh_0].initial_ressources > cells[higher].initial_ressources)
        higher = cells[index].neigh_0;
    if (cells[cells[index].neigh_1].initial_ressources > cells[higher].initial_ressources)
        higher = cells[index].neigh_1;
    if (cells[cells[index].neigh_2].initial_ressources > cells[higher].initial_ressources)
        higher = cells[index].neigh_2;
    if (cells[cells[index].neigh_3].initial_ressources > cells[higher].initial_ressources)
        higher = cells[index].neigh_3;
    if (cells[cells[index].neigh_4].initial_ressources > cells[higher].initial_ressources)
        higher = cells[index].neigh_4;
    if (cells[cells[index].neigh_5].initial_ressources > cells[higher].initial_ressources)
        higher = cells[index].neigh_5;
    return (higher);
}


int     gluecase(int my_base_index, std::vector<Cell> cells)
{
    int count = 0;
    int higher = neigh_higher(cells, my_base_index);
    if (cells[my_base_index].neigh_0 >= 0 && cells[cells[my_base_index].neigh_0].type != 0)
    {
        cout << "BEACON " << cells[my_base_index].neigh_0 << " " << 1 << ";" << "BEACON " << my_base_index << " " << 1 << ";";
        count++;
    }

    if (cells[my_base_index].neigh_1 >= 0 && cells[cells[my_base_index].neigh_1].type != 0)
    {
        cout << "BEACON " << cells[my_base_index].neigh_1 << " " << 1 << ";" << "BEACON " << my_base_index << " " << 1 << ";";
        count++;
    }

    if (cells[my_base_index].neigh_2 >= 0 && cells[cells[my_base_index].neigh_2].type != 0)
    {
        cout << "BEACON " << cells[my_base_index].neigh_2 << " " << 1 << ";" << "BEACON " << my_base_index << " " << 1 << ";";
        count++;
    }

    if (cells[my_base_index].neigh_3 >= 0 && cells[cells[my_base_index].neigh_3].type != 0)
    {
        cout << "BEACON " << cells[my_base_index].neigh_3 << " " << 1 << ";" << "BEACON " << my_base_index << " " << 1 << ";";
        count++;
    }

    if (cells[my_base_index].neigh_4 >= 0 && cells[cells[my_base_index].neigh_4].type != 0)
    {
        cout << "BEACON " << cells[my_base_index].neigh_4 << " " << 1 << ";" << "BEACON " << my_base_index << " " << 1 << ";";
        count++;
    }

    if (cells[my_base_index].neigh_5 >= 0 && cells[cells[my_base_index].neigh_5].type != 0)
    {
        cout << "BEACON " << cells[my_base_index].neigh_5 << " " << 1 << ";" << "BEACON " << my_base_index << " " << 1 << ";";
        count++;
    }
    return (count);
}

int is_even_odd(int value)
{
	if (value % 2 == 0)
		return (EVEN);
	return (ODD);
}

int	count_type_in_side(std::vector<Cell> cells, int side, int number_of_values, int type)
{
	int	i = 0;
	int count = 0;
	while (i < number_of_values)
	{
		if (is_even_odd(cells[i].index) == side && cells[i].type == type)
			count++;
		i++;
	}
	return (count);
}

void	parsing_the_distance(std::vector<Cell> cells, int index, int distance)
{
    cerr << "simple verif de parsing, mon index est de : " << index << " ma distance de la base est de : " << distance <<endl;
    if (cells[index].distance_my_base > distance)
	    cells[index].distance_my_base = distance;
	if (cells[index].neigh_0 > -1 && (cells[index].distance_my_base + 1 < cells[cells[index].neigh_0].distance_my_base))
		parsing_the_distance(cells, cells[index].neigh_0, distance + 1);

	if (cells[index].neigh_1 > -1 && (cells[index].distance_my_base + 1 < cells[cells[index].neigh_1].distance_my_base))
		parsing_the_distance(cells, cells[index].neigh_1, distance + 1);

	if (cells[index].neigh_2 > -1 && (cells[index].distance_my_base + 1 < cells[cells[index].neigh_2].distance_my_base))
		parsing_the_distance(cells, cells[index].neigh_2, distance + 1);

	if (cells[index].neigh_3 > -1 && (cells[index].distance_my_base + 1 < cells[cells[index].neigh_3].distance_my_base))
		parsing_the_distance(cells, cells[index].neigh_3, distance + 1);

	if (cells[index].neigh_4 > -1 && (cells[index].distance_my_base + 1 < cells[cells[index].neigh_4].distance_my_base))
		parsing_the_distance(cells, cells[index].neigh_4, distance + 1);

	if (cells[index].neigh_5 > -1 && (cells[index].distance_my_base + 1 < cells[cells[index].neigh_5].distance_my_base))
		parsing_the_distance(cells, cells[index].neigh_5, distance + 1);

}

class Game
{
    public:

    int total_crystal_start = 0;
    int total_crystal_now = 0;
    int my_base_index = 0;
    int opp_base_index = 0;
   	int my_tants = 10;
	int opp_tants = 10;
	int	turn = 0;
    int number_of_cells = 0; // amount of hexagonal cells in this map
    int number_of_bases = 0;
	int	number_of_crystals = 0;
	int number_of_eggs = 0;
	std::vector<Cell> cells;
	std::vector<Cell> crystals;
	std::vector<Cell> eggs;

    void	init()
    {
        int type; // 0 for empty, 1 for eggs, 2 for crystal
        int initial_resources; // the initial amount of eggs/crystals on this cell
        int neigh_0; // the index of the neighbouring cell for each direction
        int neigh_1;
        int neigh_2;
        int neigh_3;
        int neigh_4;
        int neigh_5;
        cin >> number_of_cells; cin.ignore();
        cerr << "Cells : " << number_of_cells << endl;
        for (int i = 0; i < number_of_cells; i++) {
            cin >> type >> initial_resources >> neigh_0 >> neigh_1 >> neigh_2 >> neigh_3 >> neigh_4 >> neigh_5; cin.ignore();
			Cell newcell (i, type, initial_resources, neigh_0, neigh_1, neigh_2, neigh_3, neigh_4, neigh_5, 0, 0, 100);
			cells.push_back(newcell);
			if (type == 2)
			{
                total_crystal_start += initial_resources;
				crystals.push_back(newcell);
				number_of_crystals++;
			}
			else if (type == 1)
			{
				eggs.push_back(newcell);
				number_of_eggs++;
			}
        }
        cin >> number_of_bases; cin.ignore();
            
        for (int i = 0; i < number_of_bases; i++) {
            cin >> my_base_index; cin.ignore();
        }

        for (int i = 0; i < number_of_bases; i++) {
            cin >> opp_base_index; cin.ignore();
        }
        total_crystal_now = total_crystal_start;
		//parsing_the_distance(cells, my_base_index, 0);
    }

	int get_my_tants()
	{
		return (my_tants);
	}

	int	get_opp_tants()
	{
		return (opp_tants);
	}

	int	get_number_of_cells()
	{
		return (number_of_cells);
	}

	std::vector<Cell>	get_cells()
	{
		return (cells);
	}

	void	loop()
	{
		int resources; // the current amount of eggs/crystals on this cell
		int my_ants; // the amount of your ants on this cell
		int opp_ants; // the amount of opponent ants on this cell
		int side = 0;

		side = is_even_odd(my_base_index);
		while (1)
		{
			for (int i = 0; i < number_of_cells; i++)
			{
				cin >> resources >> my_ants >> opp_ants; cin.ignore();
                if (cells[i].type == 2)
                {
                    total_crystal_now -= (cells[i].initial_ressources - resources);
                }
				cells[i].my_ants = my_ants;
				cells[i].opp_ants = opp_ants;
				cells[i].initial_ressources = resources;
				if (cells[i].initial_ressources <= 0 && (cells[i].type == CRYSTAL || cells[i].type == EGG))
                {
                    if (cells[i].type == CRYSTAL)
                    {
                        for (int j = 0; j < number_of_crystals; j++)
                        {
                            if (cells[i].type == CRYSTAL && cells[i].index == crystals[j].index)
                            {
                                crystals.erase(crystals.begin() + j);
                                number_of_crystals--;
                                break ;
                                cerr << "J'efface l'index : " << i << " Il est de type : " << cells[i].type << endl;
                            }
                        }
                    }
                    else if (cells[i].type == EGG)
                    {
                            for (int j = 0; j < number_of_eggs; j++)
                            {
                                if (cells[i].type == EGG && cells[i].index == eggs[j].index)
                                {
                                    eggs.erase(eggs.begin() + j);
                                    number_of_eggs--;
                                    break ;
                                }
                            }
                    }
					cells[i].type = GROUND;
                }
			}

			// Write an action using cout. DON'T FORGET THE "<< endl"
			// To debug: cerr << "Debug messages..." << endl;

			my_tants = my_total_ants(cells, number_of_cells);
			opp_tants = my_total_ants(cells, number_of_cells);

			// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text> 

			//gluecase(my_base_index, cells);

			int j = 0;
            int egg_farm = 0;
            int number_of_crystals_side = count_type_in_side(crystals, side, number_of_crystals, CRYSTAL);
            int number_of_eggs_side = count_type_in_side(eggs, side, number_of_eggs, EGG);
            cerr << "NUMBER OF CRYSTALS IN SIDE " << number_of_crystals_side << endl;
            cerr << "NUMBER OF CRYSTALS " << number_of_crystals << endl;
			for (int j = 0; j < number_of_crystals; j++)
			{
				if (cells[0].type == CRYSTAL && side == ODD)
                {
					cout << "LINE " << my_base_index << " " << 0 << " " << 1 << ";";
                    cerr << "LE PREMIER IF SE DECLENCHE" << endl;
                }
				if (number_of_crystals_side > 0 && (is_even_odd(crystals[j].index) == side))
                {
					cout << "LINE " << my_base_index << " " << crystals[j].index << " " << 1 << ";";
                    cerr << "LE DEUXIEME IF SE DECLENCHE : " << cells[crystals[j].index].index << " sa distance est de :" << cells[crystals[j].index].distance_my_base << endl;
                }
				else if (number_of_crystals_side == 0)
				{
					cout << "LINE " << my_base_index << " " << crystals[j].index << " " << 1 << ";";
                    cerr << "LE TROISIEME IF SE DECLENCHE" << endl;
				}
			}
            for (int j = 0; j < number_of_eggs; j++)
            {
                if ((number_of_eggs == 1 && number_of_crystals <= 2) || (my_tants - (my_tants/10) >= opp_tants))
                    break ;
                if ((total_crystal_now > total_crystal_start/2) && number_of_eggs_side > 0 && (is_even_odd(eggs[j].index) == side) && egg_farm == 0)
                {
                    cout << "LINE " << my_base_index << " " << eggs[j].index << " " << 1 << ";";
                    egg_farm = 1;
                }
                else if ((total_crystal_now > total_crystal_start/2) && egg_farm == 0 && number_of_eggs_side == 0)
                {
                    cout << "LINE " << my_base_index << " " << eggs[j].index << " " << 1 << ";";
                    egg_farm = 1;
                }
            }
            egg_farm = 0;
			cout << "WAIT;MESSAGE KWRO-42" << endl;
			turn++;
		}
	}
};

int main()
{
    Game game;
    game.init();

	game.loop();
}