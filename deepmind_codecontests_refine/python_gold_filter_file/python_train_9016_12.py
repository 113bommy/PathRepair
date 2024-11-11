n,k,m = map(int,input().split())
A = list(map(int,input().split()))
rem = []
cnt = [0]*(m+1)
a=0
for i in A:
    rem.append([i,i%m])
    cnt[i%m]+=1
    if(cnt[i%m]>=a):
        a = cnt[i%m]
        b = i%m
if(a<k):
    print("No")
else:
    print("Yes")
    for i in A:
        if(i%m == b):
            print(i,end=" ")
            k-=1
        if(k==0):
            break


        

