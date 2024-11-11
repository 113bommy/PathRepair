n,m=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
sum,j=0,0
for i in B:
    if i>(sum+A[j]):
        sum+=A[j]
        j+=1
    print(j+1,i-sum)