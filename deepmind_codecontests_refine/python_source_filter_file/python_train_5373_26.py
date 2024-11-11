def main():
	s = list(input().strip())
	k = int(input())
	n = len(s)
	u = len(set(s))
	if n < k:
		print('impossible')
	else:
		print(k - u)

if __name__ == "__main__":
	main()