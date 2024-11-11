n=int(input())
s=input()
sr=s[::-1]
a=[0]*10
for i in s:
    if i=='L':
        a[a.index(0)]=1
    elif i=='R':
        a[9-a[::-1].index(0)]=1
    else:
        a[int(i)]=0
p=''
for i in a:
    p=p+str(i)
print(int(p))