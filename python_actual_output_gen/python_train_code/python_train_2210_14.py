a=input()
b=input()
for i,j in zip(a,b):
    if i==j:
        print(0,end=" ")
    else:
        print(1,end=" ")