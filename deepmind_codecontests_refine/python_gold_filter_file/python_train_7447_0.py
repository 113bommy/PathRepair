n,h,k = map(int, input().split())
al = list(map(int, input().split()))
time=0
c = 0
index=0
while index<n:
    if index<n and c<k and c+al[index]>h:
        c=k
    while index<n and c+al[index]<=h:
        c+=al[index]
        index+=1
    time+=c//k
    c%=k
if c>0:
    time+=1
print(time)
    

