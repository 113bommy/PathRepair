a = int(input())
b = sorted(list(map(int,input().split())))
print('YES' if b[a - 2] < b[a - 1] else 'NO')