n=int(input())
s=input()
l=[0 for i in range(10)]
for c in s:
    if(c=='L'):
        for i in range(10):
            if (l[i]==0):
                l[i]=1
                break
    elif(c=='R'):
        for i in range(9,-1,-1):
            if (l[i]==0):
                l[i]=1
                break
    else:
        l[int(c)]=0
print(''.join(str(x) for x in l))