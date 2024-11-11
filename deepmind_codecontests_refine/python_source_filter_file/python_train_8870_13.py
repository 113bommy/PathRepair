import math
n,a,b,k = map(int,input().split())
arr = list(map(int,input().split()))


sum = 0
dp = [0]*n
for i in range(n):
    # you can kill the monster
    p = 0
    if a > arr[i]:
        dp[i] = p

    rem = arr[i]%(a+b)
    
    if rem == 0: # opponent is ending
        sub = arr[i] - b
        sub1 = arr[i] - sub
        p = math.ceil(sub1/a) 
        dp[i] = p

    if rem != 0:
        rem -=a
        if rem > 0: 
            p = math.ceil(rem/a)
            
        dp[i] = p  


dp.sort()
count = 0
for i in range(n):
    count+=dp[i]
    if count > k:
        break
    sum+=1

print(dp)
print(sum)
                     
                 

    