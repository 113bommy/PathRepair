n = int(input())
for i in range(n):
    t, x, y = map(int, input().split())
    if x+y>t or (x+y-t)%2 !=0:
        print('NO')
        exit()
print('YES')