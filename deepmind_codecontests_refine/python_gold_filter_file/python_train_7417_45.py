def solve(b):
	a = list()
	l = len(b)
	for i in range(0,l,2):
		a.append(b[i])

	if l%2==0:
		a.append(b[-1])
	return "".join(a)

if __name__ == "__main__":
	t = int(input())
	results = list()
	for i in range(0,t):
		b = input()
		results.append(solve(b))
	for result in results:
		print(result)

