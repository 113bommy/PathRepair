people, sports = (int(n) for n in input().split(" "))
preference = []
for _ in range(people):
    pre = [int(n) - 1 for n in input().split(" ")]
    preference.append(pre)
answer = float("inf")
use_sports = {n for n in range(sports)}
for _ in range(sports - 1):
    rank = [0 for n in range(sports)]
    for p in range(people):
        for s in (preference[p]):
            if s in use_sports:
                rank[s] += 1
                break
    answer = min(answer, max(rank))
    use_sports -= {rank.index(max(rank))}
print(answer)