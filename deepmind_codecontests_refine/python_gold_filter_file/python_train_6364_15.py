n = int(input())

l = list(map(int,input().split()))

l.sort()
min = 10**12

for t in range(1,101):
   cost = 0
   for j in range(n):
       if abs(l[j] - t) > 1:
           if l[j] > t:
               cost+=l[j] - (1+t)
           else:
               cost+=(t-1) - l[j]


   if cost<min:
      min = cost
      ans = t


print(ans,min)




