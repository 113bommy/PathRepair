n = int(input())
for i in range(n):
    s = input()
    if len(s) % 2 != 0:
        print('NO')
        continue
    if s[0: len(s)//2-1] == s[len(s)//2: -1]:
        print('YES')
    else:
        print('NO')