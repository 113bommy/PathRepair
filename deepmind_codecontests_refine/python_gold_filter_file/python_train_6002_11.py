n, m = map(int,input().split())
one_to_n = n*(n+1)//2
m = m % one_to_n
l = list(range(1,n+1))
count = -1
while True:
    count += 1
    if m > l[count]:
        m -= l[count]
    elif m == l[count]:
        print(0)
        break
    else:
        print(m)
        break
