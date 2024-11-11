n=int(input())
a=list(map(int,input().split()))

ans=[]
b=[0]*n
for i in reversed(range(n)):
  if sum(b[i::i+1])%2!=a[i]:
    b[i]+=1
    ans.append(i)
        
print(sum(b))
print(*sorted(ans))       