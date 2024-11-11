a,b,c,d=map(int,input().split())
print('YES' if abs(a-b)<=d and abs(b-c)<=d  or abs(a-c)<=d else 'NO')