x = 0
n=int(input())
for i in range(n):
    y,z=list(map(int,input().split()))
    if y+2<z:
        x += 1
print(x)