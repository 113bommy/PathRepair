n,m,c = map(str,input().split())
n,m = int(n),int(m)
l = [['.' for i in range(m+2)]]
for i in range(n):
    p = ['.']
    z = list(input())
    p+=z
    p+=['.']
    l.append(p)
l.append(['.' for i in range(m+2)])
s = set()
for i in range(1,len(l)-1):
    for j in range(1,len(l[i])-1):
        if(l[i][j]==c):
            s.add(l[i+1][j])
            s.add(l[i-1][j])
            s.add(l[i][j+1])
            s.add(l[i][j-1])
k = list(s)
co = 0
for i in range(len(k)):
    if(k[i]!=c and k[i]!='.'):
        co+=1
print(co)
