
n=int(input())
g=input()
c=0
for i in range(n-1):
    if(g[i]==g[i+1]):
        c=c+1
print(c)