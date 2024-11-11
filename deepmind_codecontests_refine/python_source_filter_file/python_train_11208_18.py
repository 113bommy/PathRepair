x=int(input())
y=list(input())
v=0
if len(y)>3:
    for i in range(x-2):
        if y[i]==y[i+1]==y[i+2]=='x':
            v+=1
    print(v)
else:print('0')


