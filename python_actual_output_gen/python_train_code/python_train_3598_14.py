def index(ch):
	return ord(ch)-ord('a')

if __name__ == '__main__':
	word = input()
	ans = 0
	prev = 0
	for ch in word:
		curr = index(ch)
		if curr > prev:
			ans += min(curr-prev, prev+(26-curr))
		else:
			ans += min(prev-curr, curr+(26-curr))
		prev = curr
	print(ans)
