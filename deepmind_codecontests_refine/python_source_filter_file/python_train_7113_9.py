"""
	Author		: Arif Ahmad
	Date  		: 
	Algo  		: 
	Difficulty	: 
"""

def main():
	n, k = map(int, input().split())

	ans = n
	l = 1
	r = n
	while l < r: 
		v = (l + r) // 2

		total = v
		x = k
		while (v//x) > 0:
			total += (v//x)
			x *= k

		if total >= n:
			ans = min(ans, v)
			r = v - 1
		else:
			l = v + 1

	print(ans)

if __name__ == '__main__':
    main()
    
