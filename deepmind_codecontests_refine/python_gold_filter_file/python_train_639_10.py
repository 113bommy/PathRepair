n,m,k = list(map(int,input().split()))
a = list(map(int,input().split()))
a.append(10**18+1)
s = 0
c = 0
init = (a[0]-1)//k
for i in range(1,m+1):
    curr = (a[i]-c-1)//k
    if curr != init:
        s+=1
        c=i
        curr = (a[i]-c-1)//k
    init = curr
print(s)