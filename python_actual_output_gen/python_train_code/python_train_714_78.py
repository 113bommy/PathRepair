A,V=map(int,input().split())
B,W=map(int,input().split())
T=input()
if ((V-W)*int(T)) <= abs(A-B):
    print('NO')
else:
    print('YES')
