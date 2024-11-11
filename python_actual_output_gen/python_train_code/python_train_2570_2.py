def return_happiness(a, b):
	total_happiness = 0
	for a_i, b_i in zip(a, b):
		if 2*a_i < b_i and b_i<=1:
			total_happiness -= 1
		else:
			total_happiness += b_i//2 * (b_i//2 + b_i%2)
	return total_happiness

n = input()

a = [int(x) for x in input().split(" ")]

b = [int(x) for x in input().split(" ")]

print(return_happiness(a, b))
