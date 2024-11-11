a,b,c=map(int,input().split())
print('YES' if a==b+c or b==a+c or c==a+b else 'NO')