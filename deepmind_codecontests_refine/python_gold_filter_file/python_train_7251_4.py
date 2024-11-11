I = lambda: map(int, input().split())

n, s = I()
T = []

for _ in range(n):
    h, m = I()
    T.append(60*h+m)

if T[0] > s:
    print(0, 0)
else:
    for i in range(n-1):
        if T[i+1]-T[i] > 2*s+1:
            print(*divmod(T[i]+s+1, 60))
            break
    else:
        print(*divmod(T[-1]+s+1, 60))