n=input()
n='0'+n
l=len(n)
flag=0
if n!=n[::-1]:
    flag=1
if n[1]=='0':
    flag=1
if flag==0:
    print(1,2)
    c=1
    for i in range(1,l-2):
        if n[i]=='1':
            print(i+1,i+2)
            c+=1
        else:
            print(c,i+2)
else:
    print(-1)