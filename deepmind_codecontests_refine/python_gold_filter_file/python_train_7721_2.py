n,m = map(int,input().split())
d={}
c=0
h=[]
for _ in range(n):
    k = input()

    for i in range(len(k)):
        if i not in d:
            d[i]=[k[i]]
        else:
            d[i]+=k[i]

l = list(map(int,input().split()))

for i in d:
    k=-1
    for j in range(5):
         k = max(k,d[i].count(chr(65+j)))
    h.append(k)
for i in range(len(h)):
    c+=h[i]*(l[i])
print(c)