n,k=map(int,input().split())
list_=list(map(int,input().split()))
list_.append(1)
list_.append(1000000000)
j=sorted(list_)
access=j[k]
if j[k]!=j[k+1]:
    print(j[k])
else:
    print("-1")