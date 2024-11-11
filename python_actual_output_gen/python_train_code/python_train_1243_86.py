str = input().split()

ice_cream = int(str[1])
disappointed_kids = 0



for i in range(int(str[0])):

	new_str = input().split()

	if new_str[0] == "+":

		ice_cream = ice_cream + int(new_str[1])

	if new_str[0] == "-":

		if (ice_cream - int(new_str[1]))> 0:

			ice_cream = ice_cream - int(new_str[1])

		else:
			disappointed_kids = disappointed_kids + 1

print(ice_cream, disappointed_kids)