a = input()
n = len(a)
m = n
if n//2 < n/2 :
    n = n//2 +1
else:
    n = n//2
b = []
for i in range(0,m,2):
    b.append(a[i])
    b.sort()
print(b)
for p in range (0,n,1):
    if p<n-1:
        print(b[p]+"+",end="")
    else:
        print(b[p])