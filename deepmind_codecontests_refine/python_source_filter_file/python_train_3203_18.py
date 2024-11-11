n=int(input())
s=input()
a=s.split('1')
k=len(a)
flag=0
if n==1:
    if s[0]=='0':
        flag=1
if len(a[0])==2 or len(a[k-1])==2:
    flag=1
else:
    for i in range(k):
        if len(a[i])==3:
            flag=1
            break
for i in range(1,n):
    if s[i-1]=='1' and s[i]=='1':
        flag=1
        break
if flag==1:
    print("No")
else:
    print("Yes")
    