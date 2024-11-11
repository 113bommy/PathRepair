a, b, c = map(int, input().split())
if (b==a and c==0) or c!=0: print('YES' if (b == a and c == 0) or ((b - a)%c == 0 and ((b>a and c>0) or (b <= a and c <= 0))) else 'NO')
else: print('NO')