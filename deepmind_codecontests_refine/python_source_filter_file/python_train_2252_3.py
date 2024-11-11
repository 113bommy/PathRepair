from math import sqrt

def check(x):
    sq = int(sqrt(x))
    while sq * sq < x:
        sq += 1
    return sq * sq == x, sq

n = int(input())
a = map(int, input().split())
sq, non_sq = 0, 0
sqs, non_sqs = [], []
for _ in a:
    res, root = check(_)
    sq += res
    non_sq += 1 - res
    if res:
        sqs.append(2 - bool(res))
    else:
        non_sqs.append(min(_ - (root - 1) ** 2, root ** 2 - _))
sqs.sort()
non_sqs.sort()
ans = 0
if sq > non_sq:
    for i in range((sq - non_sq) >> 1):
        ans += sqs[i]
elif sq < non_sq:
    for i in range((non_sq - sq) >> 1):
        ans += non_sqs[i]
else:
    pass
print(ans)