a = input().split()
b = input().split()
la = int(a[0])
ra = int(a[1])
ta = int(a[2])
lb = int(b[0])
rb = int(b[1])
tb = int(b[2])

def gcd(x,y):
    if x*y == 0:
        return x+y
    else:
        if x>y:
            return gcd(x%y,y)
        else:
            return gcd(x,y%x)

g = gcd(ta,tb)
if (la % g >= lb % g):
    temp1 = min(rb-((la%g) - (lb%g))-lb+1,ra-la+1)
    temp2 = min(ra-la+1-(g-(la%g) + (lb%g)),rb-lb+1)
    best = max(temp1,temp2,0)
else:
    temp1 = min(ra-((lb%g) - (la%g))-la+1,rb-lb+1)
    temp2 = min(rb-lb+1-(g-(lb%g) + (la%g)),ra-la+1)
    best = max(temp1,temp2,0)
print(best)