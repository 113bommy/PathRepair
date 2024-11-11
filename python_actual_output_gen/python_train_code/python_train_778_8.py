a1,a2,a3,a4=map(str,input().split())
l=list(input())
c=0
for i in range(len(l)):
    if l[i]==a1:
        c+=int(a1)
    elif l[i]==a2:
        c+=int(a2)
    elif l[i]==a3:
        c+=int(a3)
    elif l[i]==a4:
        c+=int(a4)
print(c)
c=0