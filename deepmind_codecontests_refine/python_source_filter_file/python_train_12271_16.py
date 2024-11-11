N = int(raw_input())

for i in range(N):
    line = raw_input()
    a, b, c = sorted(int(w) for w in line.split())

    if a**2 + b**2 == c**2:
        print('YES')
    else:
        print('NO')