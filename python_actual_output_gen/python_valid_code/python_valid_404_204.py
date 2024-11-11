c=0
for _ in range(int(input())):
    x,y=list(map(int,input().split()))
    if y>x:
        c+=1
print(c)

