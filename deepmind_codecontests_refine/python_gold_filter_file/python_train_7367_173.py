L,R,d=map(int,input().split())
n=0
for i in range(L,R+1):
    if i%d==0:
        n+=1
print(n)