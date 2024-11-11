n=int(input())
l=list(map(int,input().split()))
l.sort()
c=1
mc=0
for i in range(len(l)-1):
    if l[i]==l[i+1]:
        c+=1
    else:
        c=1
    if mc<c:
        mc=c
print(mc)
    
