lst=sorted(list(map(str,input().split())))
s=0
k=0
if lst.count(lst[0])==6:
    print('Elephant')
elif lst.count(lst[1])==5:
    print('Alien')
else:
    for i in range(len(lst)):
        if lst.count(lst[i])==4:
            s+=1
            for i in range(len(lst)):
                if lst.count(lst[i])==2:
                    k+=1
                    break
            break
    if s==1:
        if k==1:
            print('Elephant')
        else: print('Bear')
    else: print('Alien')