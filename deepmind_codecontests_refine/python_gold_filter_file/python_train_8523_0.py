while True:
    r, a= input().split()
    if r==a=='0': break
    print(sum(1 for i, j in zip(r, a) if i==j), sum(1 for i in range(len(r)) for j in range(len(a)) if r[i]==a[j] and i!=j))