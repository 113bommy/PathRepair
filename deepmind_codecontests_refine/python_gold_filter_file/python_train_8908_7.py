from sys import stdin
inp=stdin.readline
n=int(inp())
d=[int(x) for x in inp().split()]
v,big,small,t,c=[int(x) for x in inp().split()],max(d),min(d),0,30
while(c):
            mid,c,t=(big+small)/2,c-1,-1
            for i in range(n):
                        if abs(d[i]-mid)/v[i]>t:
                                    t=abs(d[i]-mid)/v[i]
                                    x=d[i]
            if x>mid:small=mid
            else:big=mid
print(t)