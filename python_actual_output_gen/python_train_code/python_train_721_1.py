a, b = map(int,input().split())
t = []
for _ in range(int(input())):
    t += list(map(int, input().split()))
print(1 if sum(i <= a for i in t) % 2 or sum(i >= b for i in t) % 2 or (a < i and i < b for i in t) else 0)
