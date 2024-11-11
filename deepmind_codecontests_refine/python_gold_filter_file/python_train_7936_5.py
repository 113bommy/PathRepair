

t = int(input())
for i in range(0,t):
   n = int(input())
   a = input().strip().split()
   arr = [int(x) for x in a]
   specials = [0]*(n+1)
   cum_sum = [0]*(n+1)
   for i in range(n):
     cum_sum[i+1] = cum_sum[i] + arr[i]
   for i in range(n+1):
       for j in range(i+2, n+1):
           if cum_sum[j] - cum_sum[i] <= n:
               specials[cum_sum[j] - cum_sum[i]] = 1
   count = 0
   for i in range(n):
       if specials[arr[i]] == 1:
           count+=1
   print(count)


