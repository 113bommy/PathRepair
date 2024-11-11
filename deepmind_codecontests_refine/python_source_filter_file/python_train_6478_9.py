a = input()
a = int(a)
r1 = input()
r2 = input()
r1m = r1.split()
r2m = r2.split()
z1 = 0
z2 = 0
v = 0
for i in range(a):
    if int(r1m[i]) > int(r2m[i]):
        z1 += 1
    if int(r1m[i]) < int(r2m[i]):
        z2 += 1
if z1 > z2:
    print("1")
if z1 <= z2:
    if z1 <= 0:
        print("-1")
    else:
        v = round(z2/z1)
        if  v*z1 == z2:
            v+=1 
        print(v)
        