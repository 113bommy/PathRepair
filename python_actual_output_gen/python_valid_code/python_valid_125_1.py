n=int(input())
a=list(map(int,input().split()))
cnt=[0]*7
cnt[0]=n
for b in a:
  idx=[4,8,15,16,23,42].index(b)
  cnt[idx+1]+=cnt[idx+1]<cnt[idx]
print(n-cnt[6])