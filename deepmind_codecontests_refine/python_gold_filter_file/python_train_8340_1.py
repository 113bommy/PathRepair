n=int(input())
b=[int(z)for z in input().split()]
a,c=[0],[b[0]]
for i in b[1:]:
    if i>c[-1]+a[-1]:
        a+=[i-c[-1]]
        c+=[c[-1]]
    else:
        a+=[a[-1]]
        c+=[i-a[-1]]
c.reverse()
print(*a,*c,sep=' ')