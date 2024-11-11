day = int(input())
profit = list(map(int,input().split()))
count = 1
mx = 0
for i in range(0,len(profit)-1):
    if(profit[i]<=profit[i+1]):
        count+=1
        if(count>mx):
            mx=count
    else:
        count = 1
print(mx)
