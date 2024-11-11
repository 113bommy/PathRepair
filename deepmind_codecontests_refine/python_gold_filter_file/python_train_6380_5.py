import math

def primeFactors(n,s):
    while n % 2 == 0:
        try:
            s[2]+=1
        except:
            s[2]=1
        n = n // 2

    for i in range(3, int(math.sqrt(n))+1, 2):

        while n % i == 0:
            try:
                s[i]+=1
            except:
                s[i]=1
            n = n // i

    if n > 2:
        s[n]=1
    return s


# n = 315
# primeFactors(n)

for _ in range(int(input())):
    s={}
    a,b=map(int,input().split())
    if a%b!=0:
        print(a)
    else:
        s=primeFactors(b,s)
        ans=[]
        for i in s:
            temp=a
            cnt=0
            while temp%i==0 and temp>0:
                cnt+=1
                temp//=i
            # print(i,s[i],cnt)
            ans.append(i**(cnt-s[i]+1))
        # print(s,ans)
        print(int(a//min(ans)))
            


