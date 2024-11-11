n , v = map(int , input().split())
l = list(map(int,input().split()))
l.pop()
l.sort()

if v >= sum(l):
    print('YES')
else:
    print('NO')


