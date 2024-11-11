from collections import Counter
a=input()
b=Counter(a)
c=0
d=len(a)
h=0
for i in b.values():
    if i%2!=0:
        c+=1
if c==1 and d%2!=0:
    print("first")
elif c==0 and d%2==0:
    print("first")
else:
    for i in range(1000000):
        d -= 1
        c -= 1
        h += 1
        if d%2==0 and c==0:
            break
        elif d%2!=0 and c==1:
            break

    if h%2!=0:
        print("second")
    else:
        print("first")