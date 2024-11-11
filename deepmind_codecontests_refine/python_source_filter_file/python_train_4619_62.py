c=0
for i in range(int(input())):
    a,b,c=map(int,input().split())
    if a+b+c >=2:
        c+=1
print(c)