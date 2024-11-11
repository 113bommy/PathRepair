t,s,q=map(int,input().split())
k=0
l=s
q-=1
while t>l:
    v=l*q
    l+=v
    k+=1
print(k)
