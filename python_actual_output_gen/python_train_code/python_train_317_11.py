n=int(input())
a=list(map(int,input().split()))
b=0
for i in range(n):
    if a[i]>=max(a[0:i]):
        b+=1
print(b)