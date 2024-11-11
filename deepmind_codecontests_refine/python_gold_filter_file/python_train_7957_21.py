s = input()
n = len(s)
k = int(input())
l = list(map(int, input().split()))
ans = 0
for i, ch in enumerate(s):
     ans += (i+1) * l[(ord(ch) - 97)]
m = max(l)
n = len(s)
for j in range(n,n+k):
    ans += (j + 1) * m 
    #print(j)
print(ans)