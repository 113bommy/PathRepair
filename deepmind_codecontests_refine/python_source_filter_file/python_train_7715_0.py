def doable(n,x,y,m, prefixLR, prefixUD):
	for i in range(n-m+1):
		j = i + m - 1
		dx = prefixLR[i] + prefixLR[-1] - prefixLR[j+1]
		dy = prefixUD[i] + prefixUD[-1] - prefixUD[j+1]
		if abs(x - dx) + abs(y - dy) <= m:
			return True
	return False

def main():
	n = int(input())
	s = list(input().strip())
	x,y = map(int, input().strip().split())

	k = abs(x) + abs(y)
	if k > n or k % 2 != n % 2:
		print(-1)
		return

	prefixLR = [0] * (n + 1)
	prefixUD = [0] * (n + 1)

	for i in range(n):
		prefixLR[i+1] = prefixLR[i]
		prefixUD[i+1] = prefixUD[i]
		if s[i] == 'L':
			prefixLR[i+1] -= 1
		elif s[i] == 'R':
			prefixLR[i+1] += 1
		elif s[i] == 'D':
			prefixUD[i+1] -= 1
		else:
			prefixUD[i+1] += 1

	left = 0
	right = n

	while left < right:
		mid = left + (right - left) // 2
		if doable(n,x,y,mid, prefixLR, prefixUD):
			right = mid
		else:
			left = mid + 1

	return left
	
if __name__ == '__main__':
	main()