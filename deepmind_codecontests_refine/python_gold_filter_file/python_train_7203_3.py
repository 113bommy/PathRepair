from sys import stdin
input=stdin.readline
for _ in range(int(input())):
	n=int(input());v=odd=even=0
	for i in range(n):
		x=input().rstrip('\n')
		v+=x.count('1')
		l=len(x)
		if l%2:odd+=l
		else:even+=l
	if even:
		if v%2:v-=min(v-1,even)
		else:v-=min(v,even)
	v-=min(v,odd)
	print(n-v)