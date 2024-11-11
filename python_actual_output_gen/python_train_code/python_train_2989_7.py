n=int(input())
ans=0
t = list(map(int, input().split()))
t.sort()
for i in range(0,len(t)):
    if (t[i])!=(i+1):
        ans=i
        break
if ans==0:
    ans=len(t)+1
print(ans)