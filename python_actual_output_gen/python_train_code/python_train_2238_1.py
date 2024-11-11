n = int(input())
arr1 = list(map(int,input().split()))
arr2 = list(map(int,input().split()))
c1 = 0
c2 = 0
for i in range(n):
    if(arr1[i]==0 and arr2[i]==1):
        c1+=1
    if(arr1[i]==1 and arr2[i]==0):
        c2+=1

#print(c1,c2)

if(c1==0):
    print(-1)
else:
    if(c2==0):
        print(-1)
    else:
        ans = c1//c2
        #print(c1,c2,ans)
        print(ans+1)
    