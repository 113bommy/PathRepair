a=int(input())
b=list(map(int,input().split()))
c=0
for i in range(a-1):
    if b[i]==0 and b[i+1]==b[i-1]==1:
        c+=1
        b[i+1]=0
print(c)