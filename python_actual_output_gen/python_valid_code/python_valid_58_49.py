a=int(input())
x=0
for i in range(a):
    b=input()
    if(b=='x++'):
        x+=1
    else:
        x-=1
print(x)        