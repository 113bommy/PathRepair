n,k=map(int,input().split())
d=list(map(int,input().split()))
d=d*2
ans=0
for i in range(1,k+1):
  
  for j in range(i+1):
    have=[d[n+c-j] for c in range(i)] #ここにi個の宝石を入れる
    have.sort()
    if i!=k:
      for h in range(k-i):
        if have==[] or have[0]>=0:
          break
        del have[0]
      #いらない宝石を可能な限り詰めた状態
    if sum(have)>ans:
      ans=sum(have)
print(ans)
