n = int(input())
a = list(map(int,list(input())))
lst = []
for i in a:
    if i==2:
        lst.append(i)
    elif i==3:
        lst.append(i)
    elif i==4:
        lst.extend([2,2,3])
    elif i==5:
        lst.append(i)
    elif i==6:
        lst.extend([2,3,5])
    elif i==7:
        lst.append(i)
    elif i==8:
        lst.extend([2,2,2,7])
    elif i==9:
        lst.extend([3,3,2,2,2,7])
lst.sort(reverse=True)
print(''.join(list(map(str,lst))))