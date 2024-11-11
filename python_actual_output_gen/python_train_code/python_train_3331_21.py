n=int(input())
l=[]
a=[int(i) for i in input().split()]
for i in range(0,len(a)):
    if(a[i]>1):
        l.append(a[i])
print(len(set(l)))