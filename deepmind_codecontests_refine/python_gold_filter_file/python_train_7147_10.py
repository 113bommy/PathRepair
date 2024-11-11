n,k = map(int,input().split())
a = list(map(int,input().split()))
t = list(map(int,input().split()))
sum1 =0
count = 0 
for i in range(n):
    if(t[i] == 1):
        sum1+=a[i]
    elif(t[i] == 0 and i < k):
        count+=a[i]
ans =count
i=1
#print(str(sum1) +' = sum')
while(i<n-k+1):
    #print(str(a[i]) + ' = a[i]')
    #print(str(count) + ' = count')
    if(t[i-1] == 0):
        count -=a[i-1]
    if(t[i+k-1]== 0):
        ##print(str(a[i+k]) + ' = a[i+k')
        count +=a[i+k-1]
    ans = max(count,ans)
    #print(str(ans) + '=ans')
    i+=1
print(ans + sum1)