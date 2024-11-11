k,s=map(int,input().split())
cnt=0
for i in range(s+1):
    if i>k:
        break
    cnt+= max(0,min(i+k,s)-max(s-k,s-i)+1)
print(cnt)
