a,b,c = map(int,input().split())
print('YES') if abs(b-a) == abs(c-b) else print('NO')