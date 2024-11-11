n,x,y=map(int,input().split())
p= input()
d=10**x+10**y
s=str(d)
e=p[n-x-1:]
cnt=0
for i in range(x+1):
    if e[i]!=s[i]:
        cnt=cnt+1
print(cnt)
        
