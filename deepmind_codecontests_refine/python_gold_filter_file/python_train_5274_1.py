def sss(l,r,tt):
    f = -1
    while(l<=r):
        mid = (l + r) >> 1
        if(a[mid]-a[tt] <= m):
           f = mid
           l = mid + 1
        else :
           r = mid - 1
    return f

n , m =  map(int, input().split())
a = [int(x) for x in input().split()]
f = 0
l  = len(a)
#print("l==" + str(l))
Maxx = -1
for i in range(0,l-2):
    if(a[i+2] - a[i]<= m):
         k = sss(i+2,l-1,i)
         if(k != -1):
             Maxx = max(Maxx,(a[k] - a[i+1])/(a[k]-a[i]))
if(Maxx == -1):
    print(-1)
else: print("%.15f\n" % Maxx)