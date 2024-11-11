s=0
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
for i in range(0,len(a)):
    s=s+a[i]
b.sort()
t=b[-1]+b[-2]
if s<t:
    print("YES")
else:
    print("NO")