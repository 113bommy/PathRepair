n=int(input())
ind_gr=list(range(n+1))
gr=[[i] for i in range(n+1)]
for i in range(n-1):
    x,y=map(int,input().split())
    if len(gr[ind_gr[x]])<len(gr[ind_gr[y]]):
        ind_to,ind_from=ind_gr[y],ind_gr[x]
    else:
        ind_to,ind_from=ind_gr[x],ind_gr[y]
    gr[ind_to]+=gr[ind_from]
    for i in gr[ind_from]:
        ind_gr[i]=ind_to
print(*gr[1])
