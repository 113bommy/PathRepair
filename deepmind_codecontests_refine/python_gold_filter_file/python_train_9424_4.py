n=int(input())

a=list(map(int,input().split()))

a1=sorted(a)

cnt=0

for i in a1:

    if(a1[cnt]<i):

        cnt+=1

print(cnt)
        
