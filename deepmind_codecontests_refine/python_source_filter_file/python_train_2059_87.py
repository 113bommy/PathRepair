A,V=map(int,input().split())
B,W=map(int,input().split())
T=input()
if ((V-W)*int(T)) <= A-B:
    print('NO')
else:
    print('YES')
