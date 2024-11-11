# import sys
# sys.stdin=open("input.in","r")
n,k=map(int,input().split())
# l=[] 
# q=[]
# for i in range(n):
# 	c,d=map(int,input().split())
# 	l.append(c)
# 	l.append(d)
# print(l)
# for i in range(1,n*2,2):
# 	temp=k
# 	while temp>0:
# 		if temp>l[i]:
# 			q.append(temp)
# 		temp-=1
# print(q)
d={i for i in range(1,k)}
for i in range(n):
	c,e=map(int,input().split())
	f={j for j in range(c,e+1)}
	d-=f

print(len(d))
print(*d)