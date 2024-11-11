import math

N=int(input())

ans=0
arr=[]

tmp=1

#print(int(math.sqrt(N))+5)

for i in range(int(math.sqrt(N))+5):
    tmp=1

    while N % ((i+2)**tmp) == 0:
        N=N / ((i+2)**tmp)
        #print((i+2)**tmp)
        ans+=1
        tmp+=1

    while N % (i+2) == 0:
        N = N // (i+2)

if N > 1 :
    ans+1

print(ans)
