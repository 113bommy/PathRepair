a=[0]
s=input()
c=0
for i in range(len(s)-1):
    if s[i]==s[i+1]:
        c=c+1
    a.append(c)

m=int(input())
for i in range(m):
    x,y=map(int,input().split())
    print(a[y-1]-a[x-1])


