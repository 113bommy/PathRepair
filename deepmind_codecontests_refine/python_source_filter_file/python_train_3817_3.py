input()
k=list(input())
if k.count('0')==0:
    print(1)
elif k.count('1')==0:
    print(k)
else:
    print('1',end="")
    for i in range(k.count('0')):
        print('0',end="")