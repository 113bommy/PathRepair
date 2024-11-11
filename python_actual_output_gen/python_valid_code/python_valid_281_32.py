n, m = map(int, input().split())
s = list(map(str, input().split()))
t = list(map(str, input().split()))
q = int(input())
for _ in range(q):
    x = int(input())
    x -= 1
    print(s[x%n] + t[x%n])