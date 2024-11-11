n=int(input())
a=input()
b=[0]*10
for i in range(n):
    if(a[i]=='L'):
        for j in range(10):
            if(b[j]==0):
                b[j]=1
                break
    elif(a[i]=='R'):
        for j in range(10):
            if(b[9-j]==0):
                b[9-j]=1
                break
    else:
        b[int(a[i])]=0
for i in range(10):
    print(b[i],end='')
