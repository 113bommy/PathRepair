i,o,t,j,l,s,z = map(int,input().split())
a = 2*(i//2+j//2+l//2)
if i>0 and j>0 and l>0:
    i,j,l = i-1,j-1,l-1
    b = 2*(i//2+j//2+l//2)
    print(o+max(a,b))
else:
    print(o+a)
