


n=int(input())
a=[]
for i in range(n):
    s=int(input())
    a.append(s)
z=''
z=z.zfill(n)
itog=0
for _ in range(2**n):
    for j in range(len(z)):
        if z[j]=='0':
            itog+=a[j]
            itog=itog%360
        else:
            itog-=a[j]
            if itog>=0:
                continue
            else:
                itog=360+itog

    if itog==0:
        print("YES")
        exit()
    z=int(z,base=2)
    z+=1
    z=bin(z)
    z=z[2::]
    z=z.zfill(n)
    itog=0


print("NO")


