n,m,z=map(int,input().split())
c=0
for _ in range(1,z):
    if _%n==0 and _%m==0:
        c+=1
print(c)