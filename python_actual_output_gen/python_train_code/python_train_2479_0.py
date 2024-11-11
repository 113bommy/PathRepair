n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

x=sum(b)-sum(a)
y=0
for i in range(n):
    if a[i]<b[i]:
        y+=-(a[i]-b[i])//2
print("No" if x<y else "Yes")