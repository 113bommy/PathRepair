a,b = map(int,list(input().split(" ")))
n = int(input())
c = [0 for i in range(1002)]
ans = 0
c[a]+=1
c[b]-=1
for i in range(n):
      s,f = map(int,list(input().split(" ")))
      c[s]+=1
      c[f]-=1
for i in range(1,1001):
      c[i] += c[i-1]
      if(c[i]>1):
            ans = 1
print(ans)
