def inint():
    return int(input())
def inlist():
    return list(map(int,input().split()))

def main():
    x,y,z,t1,t2,t3=inlist()
    s1=abs(z-x)*t2+2*t3+abs(y-x)*t2
    s2=abs(y-x)*t1
    if s1<=s2:print('YES') 
    else :print('NO')
    

if __name__ == "__main__":
    #import profile
    #profile.run("main()")
    main()