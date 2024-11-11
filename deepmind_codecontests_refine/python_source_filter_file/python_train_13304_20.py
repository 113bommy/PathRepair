l,r = map(int,input().split())

a = []
#r = min(r,l+2019)
for i in range(l,r):
    for j in range(i+1,r+1):
        a.append(i*j%2019)

print(min(a))
        
