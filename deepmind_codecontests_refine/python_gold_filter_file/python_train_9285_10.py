n=int(input())
i=0
m=0
k=0
a=[int(i)for i in input().split()]
a.sort()
a.reverse()
while i<n//2 :
       m+=a[i]
       k+=a[n-1-i]
       i+=1
if(n%2!=0):
    m+=a[n//2]
print(m*m+k*k)
