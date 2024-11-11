n, s = int(input()), sorted(set(map(int, input().split())))
print('YES' if len(s) < 2 or len(s) == 3 and s[2] - s[1] == s[1] - s[0] else 'NO')