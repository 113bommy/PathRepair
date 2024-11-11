y=list(map(str,input().split()))
x=int(input())
print(y[0],y[1])
print()
for i in range(x):
    f=list(map(str,input().split()))
    y[y.index(f[0])]=f[1]
    print(y[0],y[1])