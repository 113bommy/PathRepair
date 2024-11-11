n=int(input())
a=list(map(int,input().split()))
m=1
for l,r in zip(a,a[1:]):
    if abs(l-r)!=1 and l!=r:
        m=abs(l-r)
        break
for l,r in zip(a,a[1:]):
    if not(abs(l-r)==m or abs(l-r)==1 and min(l,r) % m!=0):
        print("NO")
        exit()
print("YES")
print("{} {}".format(10**9, m))
