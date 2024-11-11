k=input()
s=input()
for i,j in zip(k,s):
    if i==j:
        print(0,end='')
    else:
        print(1,end="")