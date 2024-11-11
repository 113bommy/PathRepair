f=lambda:map(int,input().split())
dl,dr=f()
ml,mr=f()

def chk(d,m):
    return m-2<d and d<2*m+3

if chk(dl,mr) or chk(dr,ml):
    print("YES")
else:
    print("NO")
