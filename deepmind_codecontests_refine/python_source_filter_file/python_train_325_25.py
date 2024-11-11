n,x,y=list(map(int,input().split()))
s=input()

val=10**x+10**y
val=str(val)
n1=len(val)


st=s[n-n1:]
sss=0
for i in range(n1):
    if st[i]!=val[i]:
        sss+=1

print(sss)



