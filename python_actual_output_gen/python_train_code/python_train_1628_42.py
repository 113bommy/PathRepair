n=list(map(int,input().split()))
n.sort()
s=n[0]+n[1]
q=n[2]
if s>q:
    print("0")
if q>=s:
    x=q-+1
    print(x)
