n=int(input())
a=list(map(int,input().split()))
p=1
for i in range(1,n):
    if a[i]>=max(a[0:i]):
        p+=1
print(p)