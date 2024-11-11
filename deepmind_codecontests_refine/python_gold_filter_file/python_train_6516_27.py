n=int(input())
s="aabb"
x=int(n/4)
y=n%4
for i in range(x):
	print(s,end="")
if y>0:
	print(s[0:y])