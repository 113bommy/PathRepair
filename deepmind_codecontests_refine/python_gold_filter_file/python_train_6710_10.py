def dectobin(n):
    r=''
    if n==0:
        return '0'
    while(n>0):
        r=str((n%2))+r
        n=n//2
    return(r)
def bintodec(n):
    r=0
    i=0
    while(n>0):
        r+=(n%10)*(2**i)
        n=n//10
        i+=1
    return r

n=int(input())
s=input()
x=bintodec(int(s[::-1]))
y=dectobin(x+1)
c=str(y)
c=c[::-1]
c=c+(max(0,n-len(c)))*"0"
cnt=0
for i in range(n):
    if s[i]!=c[i]:
        cnt+=1
print(cnt)
        
