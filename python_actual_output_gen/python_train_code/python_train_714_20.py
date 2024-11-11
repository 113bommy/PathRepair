A,V = map(int,input().split())
B,W = map(int,input().split())
T = int(input())
if (B-A) - (V - W)*T <= 0:
    print('YES')
else:
    print('NO')
