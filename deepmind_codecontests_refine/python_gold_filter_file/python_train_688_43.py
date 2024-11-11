n = int(input())
l=[0]*(n+1)
l[0]=1
l[1]=1
for i in range(2,n+1):
    l[i]=l[i-1]+l[i-2]
for i in range(1,n+1):
    if i in l:
        print('O',end='')
    else:
        print('o',end='')
print()