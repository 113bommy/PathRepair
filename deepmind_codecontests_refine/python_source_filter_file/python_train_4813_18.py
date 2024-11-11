def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
def lcm(a,b): 
    return (a*b) / gcd(a,b) 
 
for _ in range(int(input())):
    ct=float('inf')
    a,b,c=map(int,input().split())
    ca=cb=cc=0
    for pa in range(1,10**4+2):
        i=1
        while pa*i<=10**4+1:
            pb=pa*i
            j=1
            while pb*j<=10**4+1:
                pc=j*pb
                val=abs(pa-a)+abs(pb-b)+abs(pc-c)
                if val<ct:
                    ct=val
                    ca=pa
                    cb=pb
                    cc=pc
                j+=1
            i+=1
            
    print(ct)
    print(ca,cb,cc)
