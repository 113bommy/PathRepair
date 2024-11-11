a=int(input())+1
a=list(str(a))
for i in range(8000):
    k=0
    if '0' in a:
        k+=1
    if '1' in a:
        k+=1
    if '2' in a:
        k+=1
    if '3' in a:
        k+=1
    if '4' in a:
        k+=1
    if '5' in a:
        k+=1
    if '6' in a:
        k+=1
    if '7' in a:
        k+=1
    if '8' in a:
        k+=1
    if '9' in a:
        k+=1
    if k==4:
        print(''.join(a))
        break
    else:
        a=int(''.join(a))+1
        a=list(str(a))
