n,k,m,t = map(int,input().split())
c = [1]*n
pos = k-1
for _ in range(t):
    l,r = map(int,input().split())
    r-=1
    if(l==0):
        if(r<pos):
            del c[:r+1]
            pos = pos-r
        else:
            del c[r+1:]
        print(len(c),pos)
    else:
        c.insert(r,1)
        if(r<pos):
            pos+=1
        print(len(c),pos)
