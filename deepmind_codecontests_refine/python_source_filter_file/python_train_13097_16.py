n = int(input())
a,b,c = 0,0,0
for _ in range(n):
    x, y, z = map(int, input().split())
    a,b,c = max(a,b)+z,max(a,c)+y,max(b,c)+x

print(max(a,b,c))