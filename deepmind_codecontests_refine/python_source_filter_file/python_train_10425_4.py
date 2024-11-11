n, a, b = map(int,input().split())
t1, t2 = n//2, (n//2)+1
if (a==t1 and b==t1) or (a==t1 and b==t2) or (a==t2 and b==t1) or (a==t2 and b==t2):
        print('NO')
else:
    print('Yes')