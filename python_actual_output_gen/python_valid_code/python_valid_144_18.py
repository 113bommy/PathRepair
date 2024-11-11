
mn=[int(i) for i in input().split()]
m=mn[0]
n=mn[1]
c=0
l=[int(i) for i in input().split()]
for i in range(1,len(l)):
    if((l[i]-l[i-1])<=n):
        c=c+1
    else:
        c=0
print(c)
    