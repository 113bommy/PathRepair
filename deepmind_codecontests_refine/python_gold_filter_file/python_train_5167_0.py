def main():
	s = input()
	solver(s)

def solver(s):
	n = len(s)
	locs = [-1] * 26
	ks = [n+1] * 26
	for i in range(n):
		c = s[i]
		ind = index(c)
		k = i - locs[ind]
		locs[ind] = i
		maxK = ks[ind]
		if maxK == n + 1 or k > maxK:
			ks[ind] = k
#		print(i, c, ind, k, maxK, ks[ind])

	for i in range(26):
		k = n - locs[i]
		maxK = ks[i]
		if maxK == n + 1 or k > maxK:
			ks[i] = k

	bestK = min(ks)
	print(bestK)

def index(c):
	return ord(c) - ord('a')

#solver('abacaba')
#solver('zzzzz')
# solver('abcdef')
main()