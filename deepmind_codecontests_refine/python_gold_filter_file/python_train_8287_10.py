def main():
	n = int(input())
	a = int(input())
	b = int(input())
	c = int(input())

	if n == 1:
		print(0)
		return
		
	if n == 2:
		print(min(a, b))
		return

	print(min(a, b) + min(a, b, c) * (n - 2))
	return
	
main()