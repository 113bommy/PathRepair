n=int(input())
x=0
for i in range(n):
    s=input()
    if s=='x++' or s=='++x' :
        x=x+1
    else:
        x=x-1
print(x)