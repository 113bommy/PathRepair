n=int(input())
a=list(map(int,input().split()))
c=1  
for i in a:
    if i>=c:
        c+=1
print(c)