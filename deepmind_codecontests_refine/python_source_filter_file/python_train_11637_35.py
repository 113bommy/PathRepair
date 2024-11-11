"""
T E S T
"""

from collections import Counter, deque

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

cnt_a = Counter(A)
cnt_b = Counter(B)

cnt_ab = cnt_a + cnt_b

for i in cnt_ab.values():
    if i > N:
        print("No")
        exit()


print("Yes")
dq_a = deque(A)
dq_b = deque(B)

ans = []

dq_b.rotate(n // 2)

while dq_a:
    if dq_a[0] != dq_b[0]:
        dq_a.popleft()
        p = dq_b.popleft()
        ans.append(p)
        # ans.append(b.popleft())
    else:
        dq_b.rotate()
print(*ans)
