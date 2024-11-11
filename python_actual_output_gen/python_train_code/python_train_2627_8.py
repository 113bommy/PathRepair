n=input()
t=input().split()
t=[int(x) for x in  t]
t=list(set(t))
t.sort()
if(len(t)==3):
    if((t[1]-t[0])==abs(t[2]-t[1])):
        print('YES')
    else:
        print('NO')
if(len(t)<=2):
    print('YES')

else:
    print('NO')