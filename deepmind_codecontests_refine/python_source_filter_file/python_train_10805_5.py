import sys

N = int(input())
A = [list(map(lambda x: int(x) - 1, input().split(" "))) for i in range(N)]

canUse = set(range(N))

ans = 0
done = 0
while done < N:
    ans += 1
    canUseNew = set()
    print("LC", len(canUse))
    for n in canUse:
        if not A[n]:
            continue

        first = A[n][-1]
        if first in canUseNew or n in canUseNew:
            continue

        if A[first][-1] == n:
            # print("Do", n + 1, first + 1)
            A[n].pop()
            if len(A[n]) == 0:
                done += 1
            A[first].pop()
            if len(A[first]) == 0:
                done += 1
            canUseNew.add(n)
            canUseNew.add(first)

    if len(canUseNew) == 0:
        print(-1)
        sys.exit(0)
    canUse = canUseNew

print(ans)
