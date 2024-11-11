N = int(input())
tans = 1
aans = 1
for i in range(N):
    t, a = map(int, input().split())
    n = max(-(-tans // t), -(-aans / a))
    tans = n * t
    aans = n * a
print(aans + tans)