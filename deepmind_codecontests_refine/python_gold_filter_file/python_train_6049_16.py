#   https://codeforces.com/contest/1040/problem/A
n,a,b = map(int, input().split())
l = list(map(int, input().split()))
flag = False
cost = 0
for i in range((n//2)):
    if l[i] == l[n-i-1] == 2:
        cost += 2*min(a,b)
    elif (l[i] == 2 and l[n-i-1] == 0) or (l[i] == 0 and l[n-i-1] == 2):
        cost += a
    elif (l[i] == 1 and l[n-i-1] == 2) or (l[i] == 2 and l[n-i-1] == 1):
        cost += b
    elif l[i] != l[n-i-1]:
        flag = True
        break
if n&1 == 1 and l[(n//2)] == 2:
    cost += min(a,b)
print(-1 if flag else cost)
