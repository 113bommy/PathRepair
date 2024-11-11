a=input()
l=[]
for x in a:
    if x=='0':
        l.append(x)
        if len(l)==7:
            print("Yes")
            break
    else:
        l.clear()
else:
    l=[]
    for y in a:
        if y=='1':
            l.append(y)
            if len(l)==7:
                print("Yes")
                break
        else:
            l.clear()   
if len(l)!=7:
    print('NO')
        