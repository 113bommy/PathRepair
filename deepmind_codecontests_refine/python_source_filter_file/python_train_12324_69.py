t=int(input())
x=0
for i in range(t):
    s=input()
    if s=='X++':
        x+=1
    else:
        x-=1
print(x)
    