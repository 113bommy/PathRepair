 # author="_rabbit"
def pw(a,b):
    ans=1
    while(b!=0):
        if(b%2==1):
            ans=(ans*a)%100;
        #print("a=%d,b=%d,ans=%d" %(a,b,ans))
        a=(a*a)%100
        b/=2
    return ans
if __name__=="__main__":
    n=(int)(input())
    ans=pw(5,n)
    print(ans)
