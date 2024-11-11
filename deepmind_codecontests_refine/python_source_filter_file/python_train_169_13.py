n = int(input())
b = list(input())
c = dict()
for i in range(n-1):
    if b[i]+b[i+1] in c:
        c[b[i]+b[i+1]]+=1
    else:
        c[b[i]+b[i+1]]=1
g = max([c[s] for s in c])
print(c)
for s in c:
    if c[s]==g:
        print(s)
        break