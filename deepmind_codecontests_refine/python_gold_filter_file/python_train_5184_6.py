N=int(input())
A=list(map(int,input().split()))
B=[0]*(N+1)
B[0]=3

c=1
for a in A:
    c*=B[a]
    c%=1000000007
    B[a]-=1
    B[a+1]+=1

print(c)



