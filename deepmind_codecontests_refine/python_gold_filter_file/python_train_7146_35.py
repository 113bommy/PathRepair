import sys
import io, os
import math
gcd=math.gcd
ceil=math.ceil
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#arr=list(map(int, input().split()))
def dis(a,b,c,d):
    return (((a-c)*(a-c))+((b-d)*(b-d)))**(0.5)
def main():
    arr=list(map(int, input().split()))
    R=arr[0]
    x1=arr[1]
    y1=arr[2]
    x2=arr[3]
    y2=arr[4]
    a=dis(x1,y1,x2,y2)
    if(a==0):
        print(x1,y1+R/2,R/2)
        exit()
    if(R<=a):
        print(x1,y1,R)
    else:
        r=((R+a)/2)
        vector=[((((x1-x2)/a)*2*r)/2)+x2,((((y1-y2)/a)*2*r)/2)+y2]
        print(*vector,r)
if __name__ == '__main__':
    main()