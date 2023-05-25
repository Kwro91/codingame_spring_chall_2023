#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/



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
};

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

int neigh_higher(Cell *newcell, int index)
{
    int higher = 0;
    if (newcell[newcell[index].neigh_0].initial_ressources > newcell[higher].initial_ressources)
        higher = newcell[index].neigh_0;
    if (newcell[newcell[index].neigh_1].initial_ressources > newcell[higher].initial_ressources)
        higher = newcell[index].neigh_1;
    if (newcell[newcell[index].neigh_2].initial_ressources > newcell[higher].initial_ressources)
        higher = newcell[index].neigh_2;
    if (newcell[newcell[index].neigh_3].initial_ressources > newcell[higher].initial_ressources)
        higher = newcell[index].neigh_3;
    if (newcell[newcell[index].neigh_4].initial_ressources > newcell[higher].initial_ressources)
        higher = newcell[index].neigh_4;
    if (newcell[newcell[index].neigh_5].initial_ressources > newcell[higher].initial_ressources)
        higher = newcell[index].neigh_5;
    return (higher);
}


int     gluecase(int my_base_index, Cell *newcell)
{
    int count = 0;
    int higher = neigh_higher(newcell, my_base_index);
    if (newcell[my_base_index].neigh_0 >= 0 && newcell[newcell[my_base_index].neigh_0].type != 0)
    {
        cout << "BEACON " << newcell[my_base_index].neigh_0 << " " << newcell[newcell[my_base_index].neigh_0].initial_ressources << ";" << "BEACON " << my_base_index << " " << higher << ";";
        count++;
    }

    if (newcell[my_base_index].neigh_1 >= 0 && newcell[newcell[my_base_index].neigh_1].type != 0)
    {
        cout << "BEACON " << newcell[my_base_index].neigh_1 << " " << newcell[newcell[my_base_index].neigh_1].initial_ressources << ";" << "BEACON " << my_base_index << " " << higher << ";";
        count++;
    }

    if (newcell[my_base_index].neigh_2 >= 0 && newcell[newcell[my_base_index].neigh_2].type != 0)
    {
        cout << "BEACON " << newcell[my_base_index].neigh_2 << " " << newcell[newcell[my_base_index].neigh_2].initial_ressources << ";" << "BEACON " << my_base_index << " " << higher << ";";
        count++;
    }

    if (newcell[my_base_index].neigh_3 >= 0 && newcell[newcell[my_base_index].neigh_3].type != 0)
    {
        cout << "BEACON " << newcell[my_base_index].neigh_3 << " " << newcell[newcell[my_base_index].neigh_3].initial_ressources << ";" << "BEACON " << my_base_index << " " << higher << ";";
        count++;
    }

    if (newcell[my_base_index].neigh_4 >= 0 && newcell[newcell[my_base_index].neigh_4].type != 0)
    {
        cout << "BEACON " << newcell[my_base_index].neigh_4 << " " << newcell[newcell[my_base_index].neigh_4].initial_ressources << ";" << "BEACON " << my_base_index << " " << higher << ";";
        count++;
    }

    if (newcell[my_base_index].neigh_5 >= 0 && newcell[newcell[my_base_index].neigh_5].type != 0)
    {
        cout << "BEACON " << newcell[my_base_index].neigh_5 << " " << newcell[newcell[my_base_index].neigh_5].initial_ressources << ";" << "BEACON " << my_base_index << " " << higher << ";";
        count++;
    }
    return (count);
}

int main()
{
    int turn = 0;
    int crystals[50];
    int i = 0;
    while (i < 50)
        crystals[i++] = 0;
    int number_of_cells; // amount of hexagonal cells in this map
    Cell newcell[number_of_cells];
    cin >> number_of_cells; cin.ignore();
    for (int i = 0; i < number_of_cells; i++) {
        int type; // 0 for empty, 1 for eggs, 2 for crystal
        int initial_resources; // the initial amount of eggs/crystals on this cell
        int neigh_0; // the index of the neighbouring cell for each direction
        int neigh_1;
        int neigh_2;
        int neigh_3;
        int neigh_4;
        int neigh_5;
        cin >> type >> initial_resources >> neigh_0 >> neigh_1 >> neigh_2 >> neigh_3 >> neigh_4 >> neigh_5; cin.ignore();
        newcell[i].index = i;
        newcell[i].type = type;
        newcell[i].initial_ressources = initial_resources;
        newcell[i].neigh_0 = neigh_0;
        newcell[i].neigh_1 = neigh_1;
        newcell[i].neigh_2 = neigh_2;
        newcell[i].neigh_3 = neigh_3;
        newcell[i].neigh_4 = neigh_4;
        newcell[i].neigh_5 = neigh_5;
        if (type == 2)
            crystals[i] = 2;
    }
    
    int number_of_bases;
    cin >> number_of_bases; cin.ignore();
    
    int my_base_index;
    for (int i = 0; i < number_of_bases; i++) {
        cin >> my_base_index; cin.ignore();
    }

    int opp_base_index;
    for (int i = 0; i < number_of_bases; i++) {
        cin >> opp_base_index; cin.ignore();
    }



    int big_egg = where_is_big_egg(newcell, number_of_cells);
    // game loop
    while (1)
    {
        for (int i = 0; i < number_of_cells; i++)
        {
            int resources; // the current amount of eggs/crystals on this cell
            int my_ants; // the amount of your ants on this cell
            int opp_ants; // the amount of opponent ants on this cell
            cin >> resources >> my_ants >> opp_ants; cin.ignore();
            newcell[i].my_ants = my_ants;
            newcell[i].opp_ants = opp_ants;
            newcell[i].initial_ressources = newcell[i].initial_ressources - my_ants - opp_ants;
            if (newcell[i].initial_ressources <= 0)
            {
                crystals[i] = 0;
                newcell[i].type = 0;
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (newcell[big_egg].type == 0)
            big_egg = where_is_big_egg(newcell, number_of_cells);

        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text> 
        int j = 0;
        if (newcell[big_egg].type == 1 && turn < 5)
            cout << "LINE " << my_base_index << " " << big_egg << " " << big_egg << ";";
        gluecase(my_base_index, newcell);
        while (j < 50)
        {
            if (crystals[j] == 2)
            {
                cout << "LINE " << my_base_index << " " << j << " " << newcell[j].initial_ressources << ";";
            }
            j++;
        }
        cerr << "My base index neigh0 : " << newcell[my_base_index].neigh_1 << endl;
        cout << "WAIT;MESSAGE BONSOIR" << endl;
        turn++;
    }
}

//&& ((newcell[j].opp_ants * 2 > newcell[j].initial_ressources) && (newcell[j].my_ants >= newcell[j].opp_ants)