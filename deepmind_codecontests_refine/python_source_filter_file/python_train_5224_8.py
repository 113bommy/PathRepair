n=int(input())
a=input()
b=[0,0,0,0,0,0,0,0,0,0]
for x in a:
    if x=='L':
        i = 0
        for y in b:
            if y==0:
                b[i]=1
                break
            i+=1
    elif x=='R':
        i=9
        while i>=0:
            if b[i]==0:
                b[i]=1
                break
            i-=1
    else:
        b[int(x)]=0
for x in b:
    print(x,end=' ')
