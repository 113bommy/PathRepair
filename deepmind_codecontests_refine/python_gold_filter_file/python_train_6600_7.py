def gcd(a,b):
    if(a%b==0):return b;
    return gcd(b,a%b);
def solve(a,b,p,q):
    c=a*p/gcd(a,p);
    b1=b*c/a;
    q1=q*c/p;
    if(b1>=q1):
        if(b1==q1):
            print("0/1");
        else:
            d=gcd(b1-q1,b1);
            print(str(int((b1-q1)/d))+"/"+str(int(b1/d)));
        return True;
    return False;
if __name__=="__main__":
    a,b,p,q=map(int,input().split());
    if(not solve(a,b,p,q)):
        solve(b,a,q,p);