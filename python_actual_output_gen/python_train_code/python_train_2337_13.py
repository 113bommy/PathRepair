a=int(input())
b=[0]*a
c=list(map(int,input().split()))
for i in c:
    b[i-0]+=1
print(*b,sep="\n")