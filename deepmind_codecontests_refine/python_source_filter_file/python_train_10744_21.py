for _ in range(int(input())):
	r, g, b = map(int, input().split())
	if r+g<b or g+b<r or r+b<g:
		print("No")
	else:
		print("Yes")