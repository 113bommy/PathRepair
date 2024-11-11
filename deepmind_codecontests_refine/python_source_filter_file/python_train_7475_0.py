n,m=map(int,input().split())
s=input()
l=[0]
x,y=0,0
for i in range(n-1):
    if s[i]=="A" and s[i+1]=="C":x+=1
    l.append(x)
l.append(x)
print(l)
for i in range(m):
    a,b=map(int,input().split())
    print(l[b-1]-l[a-1])