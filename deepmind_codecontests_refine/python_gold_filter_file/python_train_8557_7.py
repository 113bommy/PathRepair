from collections import defaultdict
(n, k)=[int(x) for x in input().split()]

# res =-1
# dp = [1] * (n+1)
# for i in range(n,0,-1):
#     if dp[i] >= k:
#         res = i
#         break
#     imod2 = i % 2
#     if imod2 == 0:
#         dp[i//2] += dp[i]
#     else:            
#         dp[i-1] += dp[i]
#         
# print(dp)
# print(res)

# res =-1
# dp = defaultdict(lambda:1)
# for i in range(n,0,-1):
#      val = dp[i]
#      if val >= k:
#          res = i
#          break    
#      imod2 = i % 2
#      idx =-1
#      if imod2 == 0:         
#          idx = i//2
#      else:
#          idx = i-1
#      dp[idx] += val
#      del dp[i]
# print(dp)
# print(res)


#import snoop
#@snoop
def f(x):
    res = 1
    if x % 2 == 1:
        adj = 1
    else:
        adj = 2    
    res = adj    
    i = 2
    while i*x <= n:
        if i*x + adj * i - 1 <=n:
            res+= i * adj
            i*=2
        else:
            res+= (n- i*x + 1)
            break
    return res            

#import snoop
#@snoop
def find():
    lo=1
    hi=n//2
    re=1
    while lo<=hi:
        m=(lo+hi)//2;
        if f(2*m)>=k:
            re=2*m
            lo=m+1    
        else:
            hi=m-1
    lo=1
    hi=n//2 + n % 2
    ro=1
    while lo<=hi:
        m=(lo+hi)//2;
        if f(2*m - 1)>=k:
            ro=2*m -1
            lo=m+1    
        else:
            hi=m-1
    return max(re,ro)            
print(find())
