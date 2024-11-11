n=int(input())
lst=list(map(int,input().split()))
cnt=0
for i in range(5):
  if lst[i]!=i+1:
    cnt+=1
print("YES" if cnt<=2 else "NO") 