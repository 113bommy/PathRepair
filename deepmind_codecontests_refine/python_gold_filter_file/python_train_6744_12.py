a=int(input())
b=[0]*a
c=list(map(int,input().split()))
for i in c:
    b[i-1]+=1
print(*b,sep="\n")