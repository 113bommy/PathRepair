def main():
	n,k = [int(x) for x in input().strip().split()]

	minimum = min(n-k, 1)
	maximum = min(n-k, 2*k)
	print(minimum, maximum)
	
if __name__ == '__main__':
	main()