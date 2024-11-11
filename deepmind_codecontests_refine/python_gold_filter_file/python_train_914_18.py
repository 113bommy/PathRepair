n=int(input())
h=list(map(int,input().split()))
x=1
for i in range(1,n):
    if max(h[:i])<=h[i]:
        x+=1
print(x)