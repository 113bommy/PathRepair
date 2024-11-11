n=int(input())
p=list(map(int,input().split()))
a,b=map(int,input().split())
s=0
for i in range(b-a):
    s+=p[i]
print(s)