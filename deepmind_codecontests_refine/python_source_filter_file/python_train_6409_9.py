import bisect 

def anton_and_magic_potions():

	no_potions, no_fst_spell, no_snd_spell = [int(x) for x in input().split(' ')]
	initial_time, mana = [int(x) for x in input().split(' ')]
	first_spell = [int(x) for x in input().split(' ')]
	mana_first_spell = [int(x) for x in input().split(' ')]
	potions_second_spell = [int(x) for x in input().split(' ')]
	mana_second_spell = [int(x) for x in input().split(' ')]

	first_spell.append(initial_time)
	mana_first_spell.append(0)
	
	total_time = no_potions * initial_time

	for i in  range(no_fst_spell):

		if mana_first_spell[i] > mana:
			continue

		pos2 = bisect.bisect_left(mana_second_spell, mana -mana_first_spell[i]) - 1
		if pos2 >=0:
			no_potions2 = no_potions - potions_second_spell[pos2]
			res = no_potions2 * first_spell[i]
		else:
			res = no_potions * first_spell[i]
		total_time = min(total_time, res)


	print(total_time)

anton_and_magic_potions()