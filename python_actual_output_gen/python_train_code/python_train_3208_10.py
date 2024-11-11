def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
    
n,x,y=map(int,input().split())
d={}
for q in range(n):
    u,v=map(int,input().split())
    j='00'
    if u-x!=0:
        if v-y==0:
            j='0'
        else:
            s=""
            if (u-x)^(v-y):
                s="-"
            else:
                s=""
            h=gcd(abs(v-y),abs(u-x))
            j=s+str(abs(v-y)//h)+'k'+str(abs(u-x)//h)
    #print(j)
    if j in d.keys():
        d[j]+=1
    else:
        d[j]=1
j=0
for q in d.keys():
    j+=1
print(j)