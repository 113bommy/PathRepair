n,k= map(int, input().split())


s = 0
for i in range(n):
    l,r  = map(int, input().split())
    s+= r-l + 1

res = k - (s%k)
if res == 7:
    res = 0
print(res)