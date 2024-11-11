n=int(input())
b=[]
a=list(input())
for i in a:
    if i in ['0','1']:
        t=1
    elif i=='4':
        b+=['3','2','2']
    elif i=='6':
        b+=['5','3']
    elif i==8:
        b+=['7','2','2','2']
    elif i==9:
        b+=['7','3','3','2']
    else:
        b+=[i]
b=sorted(b)
print(''.join(b[::-1]))
