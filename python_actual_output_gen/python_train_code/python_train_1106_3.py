__author__ = 'Think'
n=int(input())
p=[int(i) for i in input().split()]
broken=False
for i in range(n):
	line=input()
	total=0
	for s in line:
		if s in ["a", "e", "i", "u", "o", "y"]:
			total+=1
	if total!=p[i]:
		print("NO")
		broken=True
if not broken:
	print("YES")
