M = int(input())
s = 0
t = 0
for _ in range(M):
    d, c = map(int,input().split())
    s += d * c
    t += c

ans = (s-1)//9 + t-1
print(ans)