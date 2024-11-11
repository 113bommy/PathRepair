n=int(input())
p=[]
for i in range(n):
    p.append(input())

a=0
z=0
for i in range(len(p[0])):
    for j in range(1,n-1):
        if(p[0][i]==p[j][i]):
            pass
        else:
            z=1
            break
    else:
        a+=1
    if(z==1):
        break
print(a)

