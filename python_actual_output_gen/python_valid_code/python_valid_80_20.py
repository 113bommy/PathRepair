N, M, R = map(int, input().split())

b = min(map(int, input().split()))
s = max(map(int, input().split()))

a = R % b + R // b * s

print(a,0)