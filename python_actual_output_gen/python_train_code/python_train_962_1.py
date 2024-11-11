n=int(input())
l=list(map(int,input().split()))
l=sorted(l)
m=0
c=1
# print(l)
for i in range(n-1):
    if l[i]==l[i+1]:
        c+=1
    else:
        c=1
    m=max(m,c)  
    # print(c)
print(m,len(set(l)))    