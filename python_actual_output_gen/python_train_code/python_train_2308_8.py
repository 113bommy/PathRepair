N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
prev = 10**9+1
for a,b in src:
    if a > b:
        a,b = b,a
    if a > prev:
        print('NO')
        exit()
    if b < prev:
        prev = b
    else:
        prev = a
print('YES')
