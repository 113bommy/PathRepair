M = 2147483647
a = [M for i in range(100000)]

def j_min(x,y):
    if x < y:return x
    else: return y

def find(x,y,i,l,r):
    if r<=x or y<=l:return M
    if x<=l and r<=y: return a[i]
    return min(find(x,y,i*2,l,(l+r)/2),find(x,y,i*2+1,(l+r)/2,r))

if __name__=='__main__':
    n, m = (int(x) for x in input().split())
    t=1
    while t<n :t *= 2

    for i in range(m-1,-1,-1):
        com,x,y = (int(x) for x in input().split())
        if com :
            #continue
            print(find(x,y+1,1,0,t))
        else:
            x+=t
            a[x]=y
            while isinstance(x, int) or x >= 2:
               a[int(x/2)]=j_min(a[int(x)],a[int(x)^1])
               x/=2

