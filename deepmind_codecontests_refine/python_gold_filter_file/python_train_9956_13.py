import sys

def long_division(dividend, divisor):
	ans = ""
	index = 0
	cur_dividend = int(str(dividend)[index:index + 1].ljust(1, "0"))
	dividends = set()
	while cur_dividend not in dividends:
		dividends.add(cur_dividend)
		div, mod = divmod(cur_dividend, divisor)
		yield div
		index += 1
		cur_dividend = mod
		cur_dividend = int(str(cur_dividend) + str(dividend)[index:index + 1].ljust(1, "0"))

	return None

def decimal_part(dividend, divisor):
	for i in long_division(dividend, divisor):
		if dividend == 0:
			yield i
		dividend //= 10

def solve(a, b, c):
	for index, v in enumerate(decimal_part(a, b)):
		if v == c:
			return index + 1
	return -1

print(solve(*map(int, input().split())))