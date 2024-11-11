n=int(input())
c=0
while n>0:
    d=n%10
    n=n//10
    if d==7 or d==4:
        c+=1
if c==4 or c==7 or c==44 or c==47 or c==74 or c==77:
    print("YES")
else:
    print("NO")