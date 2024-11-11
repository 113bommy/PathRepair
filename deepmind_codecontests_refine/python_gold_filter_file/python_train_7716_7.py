n = list(map(int,input().split(' ')))
s = ""
r = n[0]
k = n[0]
z = n[1]
a = []
b = 0
while k != 0:
    if k%2 == 0:
        s += "0"
    else:
        s += "1"
        a += [2**b]
    b += 1
    k = k//2
if len(a) > z or z > r:
    print("NO")
else:
    c = 0
    print("YES")
    while len(a) < z:
        if a[c] != 1:
            a.append(a[c]//2)
            a[c] = a[c]//2
        else:
            c += 1
    for i in a:
        print(i)
