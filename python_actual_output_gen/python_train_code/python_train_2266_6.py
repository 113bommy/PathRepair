n, p = map(int,input().split())
a = list(map(int,input().split()))
 
o = 0
for i in a:
    if  i % 2:
        o += 1 
e = n-o
if o != 0:
    print((2**e)*int(2**(o-1)))
else:
    if P == 0:
        print(2**n)
    else:
        print(0)