[n,m]=map(int, input().split())
for i in range(n):
    c = str(input())
    print(c)
    if c.count('*')==2:
        s1=c
    if c.count('*')==1:
        s2=c
        x=i
for i in range(m):
    if s1[i]!=s2[i]:
        y=i
print(x+1,y+1)