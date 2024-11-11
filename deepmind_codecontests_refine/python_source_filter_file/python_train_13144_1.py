T=int(input())
for _ in range(T):
    N=int(input())
    st=input()
    d={0:1}
    sm=0
    answer=0
    for i in range(N):
        sm+=int(st[i])
        if sm-(i+1) in d:
            answer+=d[sm-(i+1)]
            d[sm-(i+1)]+=1
        else:
            d[sm-(i+1)]=1
    print(d,answer)
