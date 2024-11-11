p, n = input().split()
p = int(p)
n = int(n)
if p==0 or n==0:
    print("NO")
elif p==n or n-p==1 or p-n==1:
    print("YES")
else:
    print("NO")