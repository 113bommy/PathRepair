n,m,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort(reverse = True)
s = 0
count = 0
print(a)
i = 0
while k<m and i<n:
    k+=a[i]-1
    i+=1
print(i if k>=m else -1)
