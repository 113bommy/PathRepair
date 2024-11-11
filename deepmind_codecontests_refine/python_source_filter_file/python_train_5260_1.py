import sys
n,k=map(int,sys.stdin.readline().split())
s=sys.stdin.readline()


ans=""
for i in s:
    a=ord("z")-ord(i)
    
    b=ord(i)-ord("a")
    if k==0:
        ans+=i
        continue
    if a>=b:
        if a>=k:
            ans+=chr(ord(i)+k)
            k=0
        else:
            ans+="z"
            k=k-a
    else:
        if b>=k:
            ans+=chr(ord(i)-k)
            k=0
        else:
            ans+="a"
            k=k-b
if k==0:
    print(ans)
else:
    
    print(-1)        
            