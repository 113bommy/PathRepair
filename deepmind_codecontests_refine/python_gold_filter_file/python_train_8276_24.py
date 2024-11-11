s = input()
a = int(s[:2])
b = int(s[-2:])
n = int(input())
if n == 0:
    print(s)
else:
    b = b+n
    x = b//60
    b = b % 60
    a = (a+x) % 24
    if a >= 24:
        a -= 24
    print(str(a).zfill(2)+":"+str(b).zfill(2))
