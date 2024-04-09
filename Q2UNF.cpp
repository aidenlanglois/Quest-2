/*
Guild 40
Quest 2: P vs NP
Aiden Langlois, Natali Chaaban, Mollie Dishroon, Abdallah Hussein
4/1/2024
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

//Have a display screen
void
Begin_Display ()
{
  cout << "Welcome to the Truth or Lie Labyrinth Game!\n";
  cout << "Find your way by asking sentinels questions.\n";
  cout <<
	"Some sentinels will always tell the truth, others will always lie.\n";
  cout <<
	"There is a gate at the end of the Labyrinth you must reach to exit\n\n";
}

class Sentinel
{
public:
  int Rand_Num = rand ();
  // T_or_L determines if it will lie or tell the truth
  // 0 being truth, 1 being lie
  int T_or_L = (Rand_Num % 2);
};

class Player
{
public:
  int Player_Pos = 0;
  int Previous_Pos = 0;
    vector < int >Position_History = { };
  void Update_Player_pos (int position, string choice, int Previous_Pos)
  {
	if (choice == "B")
	  {
		Player_Pos = Previous_Pos;
		Previous_Pos = Position_History.back ();
	  }
	else
	  {
		if (position == 0)
		  {
			if (choice == "L")
			  {
				Player_Pos = 1;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 2;
			  }
		  }
		else if (position == 1)
		  {
			if (choice == "L")
			  {
				Player_Pos = 3;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 4;
			  }
		  }
		else if (position == 2)
		  {
			if (choice == "L")
			  {
				Player_Pos = 4;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 5;
			  }
		  }
		else if (position == 3)
		  {
			if (choice == "L")
			  {
				Player_Pos = 6;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 7;
			  }
		  }
		else if (position == 4)
		  {
			if (choice == "L")
			  {
				Player_Pos = 7;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 8;
			  }
		  }
		else if (position == 5)
		  {
			if (choice == "L")
			  {
				Player_Pos = 8;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 9;
			  }
		  }
		else if (position == 6)
		  {
			if (choice == "C")
			  {
				Player_Pos = 10;
			  }
		  }
		else if (position == 7)
		  {
			if (choice == "L")
			  {
				Player_Pos = 10;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 11;
			  }
		  }
		else if (position == 8)
		  {
			if (choice == "L")
			  {
				Player_Pos = 11;
			  }
			else if (choice == "R")
			  {
				Player_Pos = 12;
			  }
		  }
		else if (position == 9)
		  {
			if (choice == "C")
			  {
				Player_Pos = 12;
			  }
		  }
	  }

  }
};

int
main ()
{
  srand ((unsigned) time (NULL));
  //Set the start and goal position
  Begin_Display ();
  int Goal_Pos = 13;
  Player Player1;


  // Initialize an array of the given questions
  // questions[1] is the truth, and questions[2] are lies
  string questions[][3] = {
	{"What car does Aiden Langlois drive?", "Ford Taurus", "Jeep Wrangler"},
	{"Who was the first man on the moon?", "Buzz Aldrin", "Neil Armstrong"},
	{"Who's the fastest man alive?", "Usain Bolt", "The Flash"},
	{"Who was featured in the first comic book?", "Phantom", "Superman"},
	{"Who is the oldest member of guild 40?", "Aiden", "Natali"},
	{"What is the oldest building at wayne state?", "Old Main", "State Hall"},
	{"What year was wayne state founded?", "1868", "1849"},
	{"What car does Mollie Drive?", "Chevy Malibu", "Honda Civic"},
	{"What is Aiden's Starbucks order?", "Vanilla cold brew",
	 "Caramel macchiato"},
	{"What is Mollie's Dunkin order?", "Vanilla cold brew", "Black coffee"},
	{"Who is Wayne State named after?", "Anthony Wayne", "John Wayne Gacy"},
	{"What is Aiden's Favorite flavor of Monster?", "Pipeline Punch",
	 "Zero White"},
	{"What was the first Pokemon in the pokedex?", "Bulbasaur", "Charmander"},
	{"What is the largest mammal in the world?", "Blue Whale", "Elephant"},
	{"Who painted the Mona Lisa?", "Leonardo da Vinci", "Michelangelo"},
	{"In the story of Snow White, how many dwarfs are there?", "Seven",
	 "Eight"},
	{"Which planet is known as the Blue Planet?", "Earth", "Neptune"},
	{"What is the main ingredient in the dish sushi?", "Rice", "Seaweed"},
	{"How many wives did King Henry VIII have?", "Six", "Four"},
	{"In which year did Serena Williams win her first Grand Slam singles title?", "1999", "2002"},
	{"Who is the Greek god of war and son of Zeus and Hera?", "Ares",
	 "Kratos"},
	{"In what year did the Berlin Wall fall?", "1989", "1992"},
	{"Who is known as the Father of Modern Physics?", "Albert Einstein",
	 "Robert Oppenheimer"},
	{"What is the data structure that these questions are held in?", "Array",
	 "File"},
	{"What year was Aiden born in?", "2002", "2003"},
	{"What was the first mobile telephone?", "Motorolla DynaTAC",
	 "BlackBerry 850"}
  };

  //create a vector for all of the picked questions using their indexes in the array
  vector < int >Picked_Questions;

  // Store whether the sentinels are liars or good little robots
  int Sentinel_Data[][2] = { };

  for (int i = 0; i < 13; i++)
	{
	  Sentinel MySentinel;
	  Sentinel_Data[i][0] = MySentinel.T_or_L;
	  Sentinel_Data[i][1] = 0;
	}

  cout << "You walk into the labyrinth and encounter the first sentinel.\n";

  //Start the game loop
  while (Player1.Player_Pos != Goal_Pos)
	{
	  string Player_Input;
	  string Direction;
	  for (int i = 0; i < 26; i++)
		{
		  cout << "You ask the sentinel: " << questions[i][0] << endl;
		  if (Sentinel_Data[Player1.Player_Pos][0] == 0)
			{
			  cout << "The sentinel responds: " << questions[i][1] << endl;
			  cout << "Is this the truth or a lie?\n" <<
				"Input 'T' for truth or 'L' for lie\n";
			  cin >> Player_Input;
			  if (Player_Input == "T" or Player_Input == "L")
				{
				  if (Player_Input == "T")
					{
					  cout << "You guessed correctly! Well done!\n";
					  if (Player1.Player_Pos == 0)
						{
						  cout <<
							"There's two paths, would you like to go left or right?\n";
						  cout << "'L' or 'R'?";
						  cin >> Direction;
						  if (Direction != "L" or Direction != "R")
							{
							  while (Direction != "L" or Direction != "R")
								{
								  cout << "Invalid input, try again.\n";
								  cout <<
									"There's two paths, would you like to go left or right?\n";
								  cout << "'L' or 'R'?";
								  cin >> Direction;
								}
							}
						  else
							{
							  Player1.Update_Player_pos (Player1.Player_Pos,
														 Direction,
														 Player1.Previous_Pos);
							  Player1.Position_History.
								push_back (Player1.Previous_Pos);
							}
						}
					  else if (Player1.Player_Pos ==
							   6 or Player1.Player_Pos == 9)
						{
						  cout <<
							"There's only one path forward. Would you like to continue or go back?\n";
						  cout <<
							"Input 'C' to continue or 'B' to go back.\n";
						  cin >> Player_Input;
						  while (Player_Input != "C" or Player_Input != "B")
							{
							  cout <<
								"Invalid input, please enter either 'C' or 'B'\n";
							  cin >> Player_Input;
							}

						}
					  else
						{
						  cout <<
							"There's two paths, would you like to go left or right?\n";
						  cout << "You may also go back.\n";
						  cout << "'L', 'R', or 'B'?\n";
						  cin >> Direction;
						  if (Direction != "L" or Direction !=
							  "R" or Direction != "B")
							{
							  while (Direction != "L" or Direction !=
									 "R" or Direction != "B")
								{
								  cout << "Invalid input, try again.\n";
								  cout <<
									"There's two paths, would you like to go left, right, or back?\n";
								  cout << "'L', 'R', or 'B'?";
								  cin >> Direction;
								}
							}
						  else
							{
							  Player1.Update_Player_pos (Player1.Player_Pos,
														 Direction,
														 Player1.
														 Previous_Pos);

							}
						}
					}

				}
			  else if (Sentinel_Data[Player1.Player_Pos][0] == 1)
				{
				  cout << "The sentinel responds: " << questions[i][2] <<
					endl;
				  cout << "Is this the truth or a lie?\n" <<
					"Input 'T' for truth or 'L' for lie\n";
				  cin >> Player_Input;
				  if (Player_Input == "T" or Player_Input == "L")
					{
					  if (Player_Input == "L")
						{
						  cout << "You guessed correctly! Well done!\n";
						  if (Player1.Player_Pos == 0)
							{
							  cout <<
								"There's two paths, would you like to go left or right?\n";
							  cout << "'L' or 'R'?";
							  cin >> Direction;
							  if (Direction != "L" or Direction != "R")
								{
								  while (Direction != "L" or Direction != "R")
									{
									  cout << "Invalid input, try again.\n";
									  cout <<
										"There's two paths, would you like to go left or right?\n";
									  cout << "'L' or 'R'?";
									  cin >> Direction;
									}
								}
							  else
								{
								  Player1.Update_Player_pos (Player1.
															 Player_Pos,
															 Direction,
															 Player1.
															 Previous_Pos);
								  Player1.Position_History.
									push_back (Player1.Previous_Pos);
								}
							}
						  else if (Player1.Player_Pos ==
								   6 or Player1.Player_Pos == 9)
							{
							  cout <<
								"There's only one path forward. Would you like to continue or go back?\n";
							  cout <<
								"Input 'C' to continue or 'B' to go back.\n";
							  cin >> Player_Input;
							  while (Player_Input != "C" or Player_Input !=
									 "B")
								{
								  cout <<
									"Invalid input, please enter either 'C' or 'B'\n";
								  cin >> Player_Input;
								}
							}
						  else
							{
							  cout <<
								"There's two paths, would you like to go left or right?\n";
							  cout << "You may also go back.\n";
							  cout << "'L', 'R', or 'B'?\n";
							  cin >> Direction;
							  if (Direction != "L" or Direction !=
								  "R" or Direction != "B")
								{
								  while (Direction != "L" or Direction !=
										 "R" or Direction != "B")
									{
									  cout << "Invalid input, try again.\n";
									  cout <<
										"There's two paths, would you like to go left, right, or back?\n";
									  cout << "'L', 'R', or 'B'?";
									  cin >> Direction;
									}
								}
							  else
								{
								  Player1.Update_Player_pos (Player1.
															 Player_Pos,
															 Direction,
															 Player1.
															 Previous_Pos);
								}

							}
						}
					}
				}
			  else
				{
				  while (Player_Input != "T" or Player_Input != "L")
					{
					  cout <<
						"Invalid input, please enter either 'T' or 'L'\n";
					  cin >> Player_Input;
					}
				}
			}
		}
	}


  return 0;
}

