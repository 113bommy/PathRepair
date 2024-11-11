n=int(input())
c=0
for i in range(n):
    x,b=map(int,input().split())
    if x-b>1:
        c+=1
print(c)