n=int(input())
p=list(map(int,input().split()))
a,b=map(int,input().split())
s=0
for i in range(a-1,b):
    s+=p[i]
print(s)