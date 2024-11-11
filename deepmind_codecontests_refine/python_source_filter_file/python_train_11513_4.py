n,k=map(int,input().split(' '))
d=list(map(chr,range(ord("a"),ord("z"))))
pw=str()
for i in range(k-1):
    pw+=d[i]
if(k!=n):
    for i in range(n):
        pw+=pw[i%k]
print(pw[0:n])