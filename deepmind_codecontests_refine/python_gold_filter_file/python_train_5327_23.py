t = int(input())
for _ in range(t):
    n, s, t = map(int,input().split())
    if s + t > n:
        print(max(s,t)-((s+t)-n)+1)
    else:
        print(max(s,t)+1)