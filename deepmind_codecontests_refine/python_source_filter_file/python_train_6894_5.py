def main():
	for _ in range(int(input())):
		x, y = map(int, input().split())
		if y*2 == x:
			print("YES")
		else:
			print("NO")
main()
