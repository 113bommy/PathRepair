n=int(input())
e=0
for i in range (0,n):
    ch=str(input())
    if ch=="x++" or ch=="++x":
        e+=1
    elif ch=="x--" or ch=="--x":
        e-=1
print(e)