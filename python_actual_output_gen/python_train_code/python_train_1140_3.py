n,m = map(int,input().split())




t = list(map(int,input().split()))



f=[]


for k in t:
    f.append(k)

p=0
for i in range(n):
    p+=max(t)
    t[t.index(max(t))]-=1

u=0
q=0
f.sort()



for j in range(m):
    if u<n:
        if u+f[j]<=m:
            q+=f[j]*(f[j]+1)//2
            u+=f[j]
        elif u+f[j]>m:
            for k in range(n-u):
                q+=f[j]
                f[j]-=1
            break

    else:
        break

print(p,q)
                
    
    
    
