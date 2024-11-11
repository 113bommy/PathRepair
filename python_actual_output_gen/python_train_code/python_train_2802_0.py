n,a = map(int,input().split())
b = 0
for i in range(n):
    for j in range(n):
        print((0,a)[j==b],end='')
    b+=1
    print()
