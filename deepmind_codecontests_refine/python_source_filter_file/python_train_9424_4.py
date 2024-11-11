n=int(input())

a=list(map(int,input().split()))

a=sorted(a)

cnt=0

for i in a:

    if(a[0]<i):

        cnt+=1

print(cnt)
        
