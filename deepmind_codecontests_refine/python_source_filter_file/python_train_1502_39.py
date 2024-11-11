from collections import Counter
def check_possible(b, s, c, r):
	return (r - b - s - c) >= 0
if __name__ == '__main__':
	recipe = input()
	b, s, c = map(int, input().split())
	pb, ps, pc = map(int, input().split())
	r = int(input())
	recipe = Counter(recipe)

	low = 0
	high = r
	while low < high:
		mid = (low + high + 1) // 2

		money_b = max((mid*recipe['B'] - b)*pb, 0)
		money_s = max((mid*recipe['S'] - s)*ps, 0) 
		money_c = max((mid*recipe['C'] - c)*pc , 0)

		if check_possible(money_b, money_s, money_c, r):
			low = mid
		else:
			high = mid - 1

	print(low)