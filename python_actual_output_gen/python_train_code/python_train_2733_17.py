n=int(input())
a=list(map(int,list(input())))
b=[]
for i in a:
    if i<2:
        continue
    if i==4:
        b.append(2)
        b.append(2)
        b.append(3)
    elif i==6:
        b=b+[5,3]
    elif i==8:
        b=b+[2,2,2,7]
    elif i==9:
        b=b+[3,3,2]
    else:
        b.append(i)
b=list(map(str,b))        
print(''.join(sorted(b,reverse=True)))       