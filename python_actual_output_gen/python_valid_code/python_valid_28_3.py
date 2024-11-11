def f(l,start,step):
    n=start+step
    if n>=l:
        n=n%l
    if n<0:
        n=l+n
    return n+1
        
if __name__=='__main__':
    a,b,c=map(int,input().split())
    print(f(a,b-1,c))