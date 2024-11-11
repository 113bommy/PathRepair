n=int(input())
lists=list(map(int,input().split()))

mn=2*10^5+1
cnt=0
for li in lists:
  if mn>li:
    mn=li
    cnt+=1
print(cnt)