t=int(input())
c=0
for i in range(t):
    a,b,c=map(int,input().split())
    if(a+b+c>=2):
        c+=1
print(c)