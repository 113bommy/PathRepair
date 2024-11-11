a,b = map(int,input().split())
a = -(-a // 2)
print(a)
print('YES') if a >= b else print('NO')