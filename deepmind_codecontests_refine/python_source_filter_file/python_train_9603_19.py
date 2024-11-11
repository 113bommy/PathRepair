for i in range(int(input())):
    a,b,c,d=[int(i)for i in input().split()]
    if a<=b:
        print( b)
        continue
    a-=b
    if d>=c:
        print(-1)
        continue
    from math import ceil
    print(ceil(a/(c-d)+0.5)*c+b)
    