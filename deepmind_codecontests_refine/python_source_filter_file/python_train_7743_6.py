n,k = map(int,input().split())
t = input()
k1 = 0
for i in range(n):
	if t[i] == "#":
		k1 = k1 + 1
	elif t[i] == ".":
		k1 = 0
	if k1 > k:
		print("NO")
		exit()
print("YES")
