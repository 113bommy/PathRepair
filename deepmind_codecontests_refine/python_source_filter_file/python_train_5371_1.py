
import sys
input=sys.stdin.readline


n=int(input())

bits=[]

g=0

def gcd(a,b):
    while b:
        a,b=b,a%b
    return a

for i in map(int,input().split()):
    bits.append(i%2)
    g=gcd(i,g)

if g>1:
    print("YES")
    print("0")
else:
    print(bits)
    # do the bits
    cnt=0
    for i in range(n-1):
        if bits[i]:
            if bits[i+1]:
                bits[i]=0
                bits[i+1]=0
                cnt+=1
            else:
                bits[i]=0
                cnt+=2
    if bits[n-1]:
        # flip the last lonely bit
        cnt+=2
    print("YES")
    print(cnt)
