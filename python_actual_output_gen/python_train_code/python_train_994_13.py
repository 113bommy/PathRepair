t = int(input())
for case in range(t):
    n,m = [int(i) for i in input().split()]
    l = [[int(i) for i in input().split()] for j in range(n)]
    l2 = [[0 for i in range(m)] for j in range(n)]
    r = n
    c = m
    r -= sum([1 in i for i in l])
    for i in range(m):
        c-=sum([l[j][i] for j in range(n)])
    # print(r,c)
    t = 1
    while r>0 and c>0:
        r-=1
        c-=1
        t = 1-t
    if t == 1:
        print('Vivek')
    else:
        print('Ashish')