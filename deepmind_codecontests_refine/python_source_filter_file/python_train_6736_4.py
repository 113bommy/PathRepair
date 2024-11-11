n,k,l=map(int,input().split())
*d,=sorted(map(int,input().split()))
D=[i for i in d if i<=d[0]+l]
if len(D)<n:print(0)
elif k==1:print(sum(d))
else:
    t=(len(d)-len(D)+k-2)//(k-1)
    if t>0:print(sum(D[0:(n-t)*k:k]+D[-t:]))
    else:print(sum(D[0:(n-t)*k:k]))