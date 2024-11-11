a = [int(x) for x in input().split()]
b=str(a[0])
c=str(a[1])
def getmask(q):
    s=""
    for i in q:
        if i in ["4","7"]:
            s+=i
    return s
while getmask(b)!=c:
    b=str(int(b)+1)
print(b)