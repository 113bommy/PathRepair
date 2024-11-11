n=int(input())
for i in range(n):
    m=int(input())
    d=[]
    c=list(map(int,input().split(' ')))
    d.append(c[0])
    for j in range(m):
        if c[j] in d:
            continue
        else:
            d.append(c[j])
    for i in d:
        print(i ,end=' ')
    print()