n=input().split('+')
n.sort()
for i in range(len(n)):
    if  n[i]==n[-1]:
        print(n[i])
    else:
        print(str(n[i])+'+',end='')
