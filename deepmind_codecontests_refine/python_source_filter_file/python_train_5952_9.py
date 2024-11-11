from collections import Counter

answer = []
for _ in range(int(input())):
    input()
    cnt = Counter(input().split())
    amts = [-(1 << 20), 1 << 20]
    for _, k in cnt.most_common():
        amts.append(max(0, min(amts[-1] - 1, k)))
    answer.append(str(sum(amts)))
print("\n".join(answer))