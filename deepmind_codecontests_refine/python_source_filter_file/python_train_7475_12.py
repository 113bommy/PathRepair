n,k=map(int,input().split())
s=input()
l=[0]
c=0
for i in range(1,n):
    if(s[i]=='C'):
        if(s[i-1]=='A'):
            c+=1
    l.append(c)
print(l)
for q in range(k):
    x,y=map(int,input().split())
    print(l[y-1]-l[x-1])

