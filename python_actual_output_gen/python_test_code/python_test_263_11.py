n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
m=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0])
k=-1
for i in range(3):
    if a[i]-b[i]-b[i-1]>=0:
        k=a[i]-b[i]-b[i-1]
        break
print(k,m)