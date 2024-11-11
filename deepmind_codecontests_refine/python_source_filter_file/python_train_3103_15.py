n = int(input())
w = list(map(int,input().split()))
ans = []
for i in range(1,n):
    ans.append(abs(sum(l[:i])-sum(l[i:])))
print(min(ans))