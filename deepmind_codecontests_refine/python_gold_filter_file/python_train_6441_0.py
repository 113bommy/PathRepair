while 1:
    a=[i+1 for i in range(10)]
    try:b=list(map(int,input().split()))
    except:break
    for i in b:a.remove(i)
    print('YES' if sum([1 for i in a if i<=20-sum(b[:2])])/7>=0.5 else 'NO')