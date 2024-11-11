a = list(map(int,input().split()))

if a.count(2)>=2 or a.count(3)==3 or set(a)=={2,4} or 1 in a:
    print('YES')
else:
    print('NO')