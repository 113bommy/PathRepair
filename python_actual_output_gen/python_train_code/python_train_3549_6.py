for i in range(int(input())):
    n=int(input())
    q=list(input())
    w=list(input())
    e=[]
    r=[]
    for j in range(n):
        if q[j]!=w[j]:
            e.append(q[j])
            r.append(w[j])
    if len(e)==2 and len(set(e))==len(set(r)):
        print('YES')
    else:
        print('NO')