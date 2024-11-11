n=int(input())
s=input()
c=0
if(n==1):
    print(s)
else:
    for i in range(n):
        if(s[i]=='0'):
            c+=1
    print(1,end='')
    for i in range(n-c):
        print(0,end='')