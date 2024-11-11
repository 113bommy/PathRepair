n=int(input())
s="aabbaccb"
x=int(n/8)
y=n%8
for i in range(x):
	print(s,end="")
if y>0:
	print(s[0:y-1])