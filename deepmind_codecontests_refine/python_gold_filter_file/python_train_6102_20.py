n = int(input())
a = list(map(int, input().split()))
print('YES' if n&a[0]&a[-1]&1 else 'NO')
