n= int(input())
l = sorted(list(map(int,input().split())))
ret = (l[n-1]-l[0])*(l[-1]-l[n])

if ret>0:
    for x,y in zip(l[:n],l[n:]):
        ret = min(ret, (y-x)*(l[-1]-l[0]))

print(ret)