MOD = 998244353

# return (even no of even numbers, odd no of even numbers)
def possibilities(cells, even_numbers, odd_numbers):
	if cells == 1:
		return (odd_numbers % MOD, even_numbers % MOD)
	if cells == 2:
		return ((odd_numbers ** 2 + even_numbers ** 2) % MOD,
				(2 * odd_numbers * even_numbers) % MOD)
	if cells % 2 == 0:
		result = possibilities(cells // 2, even_numbers, odd_numbers)
		return ((result[0] ** 2 + result[1] ** 2) % MOD,
				(2 * result[0] * result[1]) % MOD)
	else:
		result = possibilities(cells - 1, even_numbers, odd_numbers)
		return (
			# last one odd - must have even no of evens, even no of odds
			(odd_numbers * result[0]
			+
			# last one even - odd evens, odd odds
			even_numbers * result[1]) % MOD,
			# last one odd - odd both
			(odd_numbers * result[1]
			+
			# last one even - even both
			even_numbers * result[0]) % MOD
			)

n, m, L, R = map(int, input().split())
cells = n * m
even_numbers, odd_numbers = (R - L + 1) // 2, (R - L + 1) // 2
if (R - L + 1) % 2 == 1:
	if L % 2 == 0:
		even_numbers += 1
	else:
		odd_numbers += 1

if cells % 2 == 0:
	print(possibilities(cells, even_numbers, odd_numbers)[0])
else:
	print(sum(possibilities(cells, even_numbers, odd_numbers)))
