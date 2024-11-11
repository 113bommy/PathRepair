n=int(input())
c=0
for i in range(n):
    p,q=map(int,input().split())
    if abs(p-q)!=0:
        c+=1
print(c)