n=int(input())
t=0
for a in range(1,n+1):
    for b in range(1,n+1):
        c=a^b
        if(a+b<=c or c>n or a>c or b>c):
            continue
        else:
            t+=1
print(t)