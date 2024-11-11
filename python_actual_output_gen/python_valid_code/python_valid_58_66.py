a=int(input())
i=0
g=0
while (i<a):
    i=i+1
    b=input()
    if str(b)=="x++" or str(b)=="x++":
        g+=1
    elif str(b)=="x--" or str(b)=="--x":
        g-=1
print(int(g))
