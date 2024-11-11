n = int(input())
a = input().split()
#print(a)
line=0
mx=0
ln=0
for i in range (n):
    if (a[n-i-1]=='1') and (i !=(n-1)):
        ln=ln+1
    else:
        break
for i in range (n-ln):
    if (a[i]=='1'):
        line=line+1
    if (i==0) and (a[i]=='1') and (a[n-1]=='1'):
        line=line+ln
    if (a[i] == '0'):
        mx = max(line, mx)
        line =0
if (mx!=0):
    print(mx)
else:
    print(line)