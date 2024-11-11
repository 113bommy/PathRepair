l, d, v, g, r=map(int,input().split())
t1=d/v
if t1%(g+r)<g:
    print(l/v)
else:
    print((g+r)*(1+t1//(g+r))+(l-d)/v)