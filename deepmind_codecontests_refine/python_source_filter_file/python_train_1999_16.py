n, k = map(int, input().split())
A = list(map(int, input().split()))


msgs = []
for a in A:
    if a not in msgs:
        if len(msgs) == k:
            msgs.pop()
        msgs.append(a)
print(len(msgs))
print(*msgs[::-1])
