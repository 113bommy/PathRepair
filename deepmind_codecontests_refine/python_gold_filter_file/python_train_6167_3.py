t=int(input())
for y in range(t):
    n=int(input())
    l=input()
    a=''
    b=''
    j=0
    for i in range(n):
        if(l[i]=='2'):
            a=a+'1'
            b=b+'1'
        elif(l[i]=='1'):
            a=a+'1'
            b=b+'0'
            j=i
            break
        else:
            a=a+'0'
            b=b+'0'
    if(j):
        a=a+(n-1-j)*'0'
        b=b+l[j+1:]
    print(a)
    print(b)