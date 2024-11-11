def myint(a):
    if a[0]=="(":
        a=a[1:-1]
    return int(a)
n,p,k = map(int, input().split())
ls=["("+str(p)+")"]
for i in range(1,k+1):
    if p+i<=n:
        ls.append(str(p+i))
start = p-k
if start<1: start=1
for i, x in enumerate(range(start,p)):
    ls.insert(i, str(x))
print(ls)
if myint(ls[0])>1:
    ls.insert(0,"<<")
if myint(ls[len(ls)-1])<n:            
    ls.append(">>")
print(" ".join(ls))