n=int(input())
l=list(map(int,input().split()))
s=sum(l)
l.sort()
if l[-1]>s or s%2==1:
    print('NO')
else:
    print('YES')
