n=int(input())
a=list(map(int,input().split()))
b=1
for i in range(n-1):
    if a[i+1]>=max(a[0:i+1]):
        b+=1
print(b)