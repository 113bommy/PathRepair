def get():
    q = list(map(int,input().split()))
    if len(q) == 1:
        [q] = q
    return q

n,d = get()
e = get()
for r in range(e):
    a,s = get()
    if 2*n-d>=a+s>=d and -d<=a-s<=d :
        print('YES')
    else:
        print('NO')