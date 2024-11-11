A,B,K=map(int,input().split())
count=0
i=min(A,B)
while count<K:
    i-=1
    if A%i==0 and B%i==0:
        count+=1
print(i)