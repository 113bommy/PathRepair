n=int(input())
q=[int(input()) for i in range(n)]
w=sorted(q)
if w[0]==w[-1]:
    print('Exemplary pages.')
    exit()
if (w[0]+w[-1])%2 or (n>2 and (w[n-2]!=w[1] or w[1]!=(w[0]+w[-1])//2)):
    print('Unrecoverable configuration.')
    exit()
x,y=q.index(min(w)),q.index(max(w))
print((q[y]-q[x])//2,' ml. from cup #',x+1,' to cup #',y+1,'.',sep='')