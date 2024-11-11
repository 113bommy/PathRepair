def solN():
    n,m=map(int,input().split())
    r=list(map(int,input().split()))
    i,res,t=0,pow(10,9),0
    for j,k in enumerate(r):
        i+=k
        if j>m-1:i-=r[j-m]
        if j>=m-1 and i<res:
            res=i
            t=(j-m)+1
    print(t+1)
def main():
    solN()
if __name__ == '__main__':
    main()