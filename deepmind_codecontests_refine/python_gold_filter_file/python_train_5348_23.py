st=input()
s=""
n=len(st)
check=0
for i in range(n):
    if st[i]=='0':
        s=st[:i]+st[i+1:]
        check=1 
        break
if check==0:
    print(st[:n-1])
else:
    print(s)