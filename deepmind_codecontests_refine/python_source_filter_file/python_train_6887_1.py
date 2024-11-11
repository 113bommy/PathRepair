import math
n = int(input())
l = int(input())
m = 0


imp = math.log(l,n)
if n == 10:
    imp = math.log10(l)
if (imp - int(imp)<0.000000001)and imp > 1:
    m = 1

    imp = int(imp) - 1
elif n == l:
    m = 1
    imp = 0




if m == 1:
    print("YES")
    print(imp)
else:
    print("NO")
