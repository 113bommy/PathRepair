a=int(input())
step=0
while(a>0):
    if int(a/5)>0:
        step+=int(a/5)
        a=a%5
    elif int(a/4)>0:
        step+=int(a/4)
        a=a%4
    elif int(a/3)>0:
        step+=int(a/3)
        a=a%3
    elif int(a/2)>0:
        step=int(a/2)
        a=a%2
    else:
        step+=int(a/1)
        a=step
print(step)