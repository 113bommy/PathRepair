def main():
	n = int(input())
	a = tuple(map(int, input().split()))
	all_set = set()
	twice_set = set()
	for ai in a:
		if ai in all_set:
			twice_set.add(ai)
		else:
			all_set.add(ai)
	res = 0
	for ai in a:
		pow_of2 = 2**29
		while pow_of2 > ai:
			aj = pow_of2-ai
			if aj in all_set and (aj != ai or aj in twice_set):
				break
			pow_of2 //= 2
		else:
			res += 1
	print(res)
main()
