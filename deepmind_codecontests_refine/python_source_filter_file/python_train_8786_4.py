n = int(input())
r = list(map(int,input().split()))
x,y = map(int,input().split())
a = sum(r)
b = 0
for i in range(n):
    b+=r[i]
    if b<x:
        pass
    elif b>=x:
        if x<=(a-b)<=y:
            print(i+2)
            exit(0)
    elif b>y:
        print(0)
        exit(0)
print(0)