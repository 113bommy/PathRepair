a=int(input())
r=0
for i in range(a):
    b=input()
    if(b=='++x' or b=='x++'):
        r=r+1
    else:
        r=r-1
print(r)