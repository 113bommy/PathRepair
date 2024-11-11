a,b=list(map(int,input().split()))
c,d=list(map(int,input().split()))
print('YES' if (b-c<=1 and c/b<=2) or (a-d<=1 and d/a<=2) else 'NO')