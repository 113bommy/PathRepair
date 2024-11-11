x,y=map(int,input().split())
n=int(input())
a=[x,y]
for i in range(2,6):
        a.append(y-x)
        x=y
        y=a[i]
print(a)
n=(n-1)%6
print(a[n]%1000000007)
