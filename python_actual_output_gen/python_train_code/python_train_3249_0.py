n,k = map(int,input().split())
s = 0
a = 0
l = []
f = False
for i in range(n+1):
    v = input()
    if v == '?':
        a += 1
        if k == 0 and i == 0:
            f = True
    elif a==0:
        l.append(int(v))
l.reverse()
if a == 0 and k != 0:
    for i in l:
        s = k*s + i
        if s > 10**18 or s < -10**18:
            break
if k == 0 and ((not f and l[-1] == 0) or (f and n%2==1)):
    print("Yes")
elif k == 0:
    print("No")
elif (a == 0 and s == 0) or (n%2 == 1 and a > 0):
    print("Yes")
else:
    print("No")