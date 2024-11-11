a=list(input())
for i in range(0,len(a)-2):
    if a[i]=='1' and a[i+1]=='4' and a[i+2]=='4':
        a[i]='0'
        a[i+1]='0'
        a[i+2]='0'
for i in range(0,len(a)-1):
    if a[i]=='1' and a[i+1]=='4':
        a[i]='0'
        a[i+1]='0'
for i in range(0,len(a)):
    if a[i]=='1':
        a[i]='0'
flag=1
for i in range(0,len(a)):
    if a[i]!='0':
        print("NO")
        flag=0
        break
if flag==1:
    print("YES")
