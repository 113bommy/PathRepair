n = int(input())
x, y = map(int,input().split())
u, v = [], []
x += 0.0001
y -= 0.0001
for i in range(n):
    k, m = map(int, input().split())
    u += [(k*x+m, i)]
    v += [(k*y+m, i)]
u, v = sorted(u), sorted(v)
for i in range(n):
    if  u[i][1] != v[i][1]:
        print('YES')
        break
else:
    print('NO')
    
