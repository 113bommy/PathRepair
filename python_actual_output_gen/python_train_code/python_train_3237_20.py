n,k = list(map(int,input().split()))
f = list(map(int,input().split()))
c = 0
for i in f:
    if i >=f[k+1] and i>0:
        c+=1
print(c)