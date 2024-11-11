a = input()
b = int(a)
if b>=0:
    print(a)
else:
    if int(a[-1])>=int(a[-2]):
        b = int(a[0:-2])
    else:
        b = int(a[0:-3]+a[-1])
    print(b)
