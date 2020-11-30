#include <iostream>
#include <map>

struct Step
{
	std::string player;
	int points;
};
int count_winners(std::map<std::string, int>& scores, int& max);
void apply_step(std::map<std::string, int>& scores, Step& step);

int main(int argc, char const* argv[])
{
	int lim;                                // number of steps
	std::cin >> lim;                        // read limit

	std::string player;                     // current player
	int points;                             // current point change

	std::map<std::string, int> scores = {}; // scores map
	Step* step_list = new Step[lim];       // steps

	std::string winner = "";                // current winner
	int max = 0;                            // current max score

	for (size_t i = 0; i < lim; i++)
	{
		// read game step
		std::cin >> player >> points;
		step_list[i] = { player, points };
		apply_step(scores, step_list[i]);
	}
	for (const auto& kv : scores)
	{
		if (kv.second > max)
		{
			winner = kv.first;
			max = kv.second;
		}
	}
	if (count_winners(scores, max) > 1)
	{
		int i = 0;
		for (size_t i = 0; i < lim; i++)
		{
			if (scores.count(step_list[i].player) > 0)
			{
				apply_step(scores, step_list[i]);
				if (scores[step_list[i].player] >= max)
				{
					winner = step_list[i].player;
					break;
				}
			}
		}
	}
	std::cout << winner << std::endl;
	return 0;
}

void apply_step(std::map<std::string, int>& scores, Step& step)
{
	if (scores.count(step.player) < 0)
		scores[step.player] = step.points;
	else
		scores[step.player] += step.points;
}

int count_winners(std::map<std::string, int>& scores, int& max)
{
	int cont = 0;
	std::map<std::string, int> keep = {};
	for (const auto& kv : scores)
	{
		if (kv.second == max)
		{
			keep[kv.first] = 0;
			cont++;
		}
	}
	scores = keep;
	return cont;
}