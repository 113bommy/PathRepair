n=int(input())
sl=list(map(int,input().strip().split()))
k=min(sl)
m=max(sl)
s1=sl.count(k)
s2=sl.count(m)
if m-k==0:
    print(m-k,((len(sl)-1)*n)//2)
else:
    print(m-k,s1*s2)