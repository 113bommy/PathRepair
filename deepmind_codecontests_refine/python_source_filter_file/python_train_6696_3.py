import sys
import io, os
import math
gcd=math.gcd
ceil=math.ceil
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#arr=list(map(int, input().split()))
def print(x, end='\n'):
    sys.stdout.write(str(x) + end)
def main():
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=list(map(int, input().split()))
        arr=[0]+arr+[0]
        lis=[0]*(n+1)
        if(n==1):
            print(min(arr[1],n))
            continue
        for i in range(n+1):
            lis[i]=arr[i+1]-arr[i]
        c=0
        for i in range(n+1):
            c+=abs(lis[i])
        for i in range(n):
            prev=lis[i]
            nex=lis[i+1]
            if(prev>0 and nex<0):
                c-=min(abs(prev),abs(nex))
        print(c)
            
if __name__ == '__main__':
    main()