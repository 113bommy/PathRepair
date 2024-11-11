n = int(input())
q = map(int,input().split())
rs = 10000000
for i in range(n):
    t = list(map(int,input().split()))
    rs = min(rs, sum(t)*5 + 15)
print(rs)

