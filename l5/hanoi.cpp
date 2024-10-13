#include <iostream>
#include <vector>

struct rod
{
    int tower_num;
    std::vector<int> disks;
};

//helper function for printing out rods
void printRods(rod &sr, rod &dr, rod &r)
{
    //print out
    std::cout << "SOURCE ROD - ROD 1" << std::endl;
    for (int disk : sr.disks)
    {
        std::cout << disk << " ";
    }
    std::cout << std::endl;

    std::cout << "DESTINATION ROD - ROD 2" << std::endl;
    for (int disk : dr.disks)
    {
        std::cout << disk << " ";
    }
    std::cout << std::endl;

    std::cout << "SOURCE ROD - ROD 3" << std::endl;
    for (int disk : r.disks)
    {
        std::cout << disk << " ";
    }
    std::cout << std::endl;
};

//helper function for moving disks
void moveDisk(rod &r1, rod &r2)
{
    int disk = r1.disks.back();
    r2.disks.push_back(r1.disks.back());
    r1.disks.pop_back();

    std::cout << "Move disk " << disk << " from tower " << r1.tower_num << " to tower " << r2.tower_num << std::endl;
}

void hanoiSolve(int num_disks, int source_rod, int destination_rod, rod &src, rod &dest, rod &other)
{

    //base case if there is only one disk left move it directly to destination rod
    if(num_disks == 1)
    {
        moveDisk(src, dest);
        return;
    }

    //recursive case: move n-1 disks to other rod
    hanoiSolve(num_disks-1, source_rod, destination_rod, src, other, dest);

    //move the largest disk to the destination rod
    moveDisk(src, dest);

    //move the n-1 disks from other rod to destination rod
    hanoiSolve(num_disks-1, source_rod, destination_rod, other, dest, src);

}

int main(int argv, char* argc[])
{
    //get number of disks
    int num_disks = std::stoi(argc[1]);
    //get source rod number
    int source_rod = std::stoi(argc[2]);
    //get destination rod number
    int destination_rod = std::stoi(argc[3]);

    //create the rods
    rod s_rod = {source_rod};
    rod d_rod = {destination_rod};
    //get other tower num
    rod o_rod = {6-(source_rod+destination_rod)};
    //add disks to source rod
    for(int i = num_disks; i > 0; i--)
    {
        s_rod.disks.push_back(i);
    }
    //create array that stores the s_rod.disks before any moves
    std::vector<int> solution = s_rod.disks;

    hanoiSolve(num_disks, source_rod, destination_rod, s_rod, d_rod, o_rod);



    return 0;
}
