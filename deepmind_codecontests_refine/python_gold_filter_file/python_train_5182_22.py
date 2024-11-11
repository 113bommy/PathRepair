N, K = map(int,input().split())
p = list(map(int,input().split()))
c = list(map(int,input().split()))
K = K-1
ans = -10**9-1
for h in range(N):
   i = h+1
   start = i
   circle = [c[i-1]]
   i = p[i-1]
   while i != start:
      score = circle[-1] + c[i-1]
      circle.append(score)
      i = p[i-1]
   l=len(circle)
   for j in range(min(l, K+1)):
      if circle[l-1] > 0:
         score = circle[j] + ((K - j)//l)*circle[l-1]
      else:
         score = circle[j]
      ans = max(score, ans)      
print(ans)