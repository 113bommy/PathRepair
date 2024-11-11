n,k = map(int, input().split())
x = input()

a = x.index("G")
b = x.index("T")
a,b = min(a,b), max(a,b)
if abs(a-b)%k==0:
    out = True
    for i in range(abs(a-b)//k):
        if x[a+k]!="." and x[a+k]!="T":
            out = False
            break
        else:
        	a+=k
    if out:
        print("YES")
    else:
        print("NO")
else:
    print("NO")