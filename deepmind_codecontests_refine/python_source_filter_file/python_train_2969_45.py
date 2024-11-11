l = [*map(str,input().split())]
if l[2][0]=='w':
    print(52 if int(l[0]) in [4,5] else 53)
else:
    a=int(l[0])
    if a in [30,29]:
        print(11)
    elif a==31:
        print(7)
    else:
        print(12)
    