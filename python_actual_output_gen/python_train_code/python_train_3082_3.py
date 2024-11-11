n=int(input())
p=[*map(int,input().split())]
r=[]
for i in range(n):
 s=[1]*n
 while s[i]:
     s[i]=0
     i=p[i]-1
 r+=[i+1]
print(r)