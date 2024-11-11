
n,m,k=map(int,input().split())
z=k%(2*m)
if z!=0:
    r=int((k/(2*m)))+1
else:
    r=int(k/(2*m))

if k%2==0:
    s="R"
else:
    s="L"

v=k-2*(r-1)

if v%2!=0:
    d=int(v/2)+1
else:
    d=int(v/2)

print(r,d,s)














