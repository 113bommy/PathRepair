x = int(input())
for a in range(1,x+1):
    for b in range(1,x+1):
        if a%b==0 and (a*b>x>a//b):
            print(a,b)
            exit()
print(-1,-1)
