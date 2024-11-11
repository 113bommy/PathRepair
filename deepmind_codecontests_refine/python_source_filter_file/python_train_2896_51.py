#XorではなくAND
#上の桁優先、不可能なら無視
import bisect
n,k=map(int, input().split())
a_ = list(map(int, input().split()))

a = []

for i in range(n):
    a_sm = a_[i]
    a.append(a_sm)
    for j in range(i+1,n):
        a_sm+=a_[j]
        a.append(a_sm)

a.sort()
#print(a)
ans = 0
for j in range(41,-1,-1):##10**9を1000個足すので30では足りない
    x = 1<<j
    t = bisect.bisect_left(a,x)
    if t<=len(a)-k-1:###
        ans+=x
        a = a[t:]
        """
        for i in range(len(a)):
            a[i]&=(x-1)
        print(a)
        """
    for i in range(len(a)):
        a[i]&=(x-1)
        
    a.sort()
print(ans)
   
