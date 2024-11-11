a=int(input())
if a<0:
    if str(a)[-1]>str(a)[-2]:
        print(str(a)[:-1])
    else:
        print(0-int(str(a)[1:-2]+str(a)[-1]))
else:
    print(a)