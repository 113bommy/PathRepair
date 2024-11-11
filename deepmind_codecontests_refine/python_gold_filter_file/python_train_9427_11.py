n,k=[int(x) for x in input().split()]
l=[]
for i in range(n):
	l.append(input())
s=input()
t=0
v=0
for j in range(len(l)):
	if len(l[j])<len(s):
		t+=1
	if len(l[j])==len(s):
		v+=1
p=t+(t//k)*5
d=t+v+((t+v-1)//k)*5
print(p+1,d)