a=[int(v) for v in input().split()]
b=7-max(a)
if b in [1,5]:
    print(str(b)+'/'+'6')
elif b in [2,4]:
    print(str(b/2)+'/'+'6')
elif b==3:
    print('1/2')
else:
    print('1/1')