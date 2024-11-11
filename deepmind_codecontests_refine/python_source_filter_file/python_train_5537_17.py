import sys

def main():
	a1 = int(input())
	a2 = int(input())
	k1 = int(input())
	k2 = int(input())
	n = int(input())
	a = n - (k1 - 1) * a1 - (k2 - 1) * a2
	print(a, end=' ')
	if k1 > k2:
		k1, k2 = k2, k1
		a1, a2 = a2, a1
	if n > k1 * a1:
		print(a1 + (n - k1 * a1) // k2)
	else:
		print(n // k1)
		
if __name__ == '__main__':
	main()
