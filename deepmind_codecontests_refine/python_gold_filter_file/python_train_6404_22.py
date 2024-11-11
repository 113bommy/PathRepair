a=input()
b=input()
for e,j in zip(a,b):
    if e==j:
        print(0,end='')
    else:
        print(1,end='')