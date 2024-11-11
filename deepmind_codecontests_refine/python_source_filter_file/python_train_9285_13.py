
n=int(input())
arr=list(map(int, input().split()))
arr.sort()
x=0
y=0
if n>=2:
    for i in range(n//2):
        x=x+arr[n-1-i]
        y=y+arr[i]
        if n//2<n/2:
            x=x+arr[n-2-i]
else:
    x=x+arr[0]
    y=0

root=(x*x)+(y*y)
print(root)