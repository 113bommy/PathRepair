n, m = map(int,input().split())
one_to_n = n*(n+1)//2
n = n % one_to_n
l = list(range(1,n+1))
count = -1
while True:
    count += 1
    if n > l[count]:
        n -= l[count]
    elif n == l[count]:
        print(0)
        break
    else:
        print(n)
        break
