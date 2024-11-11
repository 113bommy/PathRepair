from itertools import product
 
def solve():
	N = int(input())
	S = [0 if i == 'o' else 1 for i in input()]
 
	for i, j in product(range(2), repeat=2):
		pattern = [i, j] + [0] * (N - 2) 
		for k in range(2, N):
			pattern[k] = (pattern[k - 1] + pattern[k - 2] + S[k] ) % 2
		if S[-1] != (pattern[-2] + pattern[-1] + pattern[0]) % 2 : 
			continue
		if S[0] != (pattern[-1] + pattern[0] + pattern[1]) % 2 :
			continue 	
		answer = [ 'S' if pattern[k] == 0 else 'W' for k in range(N)]
		print(''.join(answer))
		return None
	print(-1)
 
if __name__ == '__main__':
	solve()