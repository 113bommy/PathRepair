n=int(input())
s=input()
c=[0,0]
d=0
for i in range(n-1):
    if c[0]==c[1] and s[i]==s[i-1] and i>0:
        d=d+1
    if s[i]=="R":
        c[0]=c[0]+1
    elif s[i]=="U":
        c[1]=c[1]+1
    print(c)
print(d)
        
        
        
        