L,d,v,g,r=map(int,input().split())
t1=d/v
faza=t1%(g+r)
if faza>g:
    t2=g+r-faza
else:
    t2=0
t3=(L-d)/v
print(t1+t2+t3)
