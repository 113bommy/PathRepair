n = int(input())
for _ in range(n):
    t = input()
    a = t.count('A')
    b = t.count('B')
    c = t.count('C')
    if (a == b and c == 0) or (c == b and b == 0) or ( b - c - a == 0):
        print('YES')
    else:
        print('NO')
