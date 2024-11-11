from bisect import bisect_left 
def calc(a,b,c):
    return (a-b)**2 + (b-c)**2 + (c-a)**2 
def nearest(r,x):
    yi = bisect_left(r,x)
    if yi==0:
        y = r[0]
    elif yi==len(r):
        y = r[-1]
    else:
        y = r[yi] if (x-r[yi])<(x-r[yi-1]) else r[yi-1]
    return y
T = int(input())
for _ in range(T):
    l = list(map(int,input().split()))
    R = list(map(int,input().split()))
    G = list(map(int,input().split()))
    B = list(map(int,input().split()))
    R.sort()
    G.sort()
    B.sort()
    ans = []
    for r,g,b in ((R,G,B),(R,B,G),(B,R,G)):
        for x in g:
            y = nearest(r,x)
            z = nearest(b,x)
            ans.append(calc(x,y,z))
    print(min(ans))            