n=int(input())
a=list(map(int,input().split()))
c=1
for i in range(1,n):
    if max(a[:i])<=a[i]:
        c+=1
print(c)