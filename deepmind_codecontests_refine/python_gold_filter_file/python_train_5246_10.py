def main():
	
	n = int(input())
	a = input()

	s = None # start
	t = None # end 
	for i in range(n - 1):
		if a[i] == '.':
			continue

		if not s and a[i] == 'R':
			s = i + 1

		if a[i] == 'R' and a[i + 1] == '.':
			t = i + 2
		if a[i] == 'R' and a[i+1] == 'L':
			t = i + 1


	for i in range(n):
		if not t and a[i] == 'L':
			t = i
		if not s and a[i] == 'L' and a[i+1] == '.':
			s = i + 1

	print(s, t)



if __name__ == '__main__':
	main()

