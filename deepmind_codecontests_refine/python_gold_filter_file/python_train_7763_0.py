memo = {}


def get_reachable_states(k, max_allowed):
    states = []
    for i in range(1, min(k,max_allowed) + 1):
        new_k = k - i
        states.append((new_k, i - 1))
    return states


def Grundy(k, max_allowed):
    if k == 0:
        return 0
    if (k, max_allowed) in memo:
        return memo[(k, max_allowed)]
    reachable_states = get_reachable_states(k, max_allowed)

    if len(reachable_states) == 0:
        memo[(k, max_allowed)] = 0
        return 0
    s = set()
    for state in reachable_states:
        s.add(Grundy(*state))
    i = 0
    while i in s:
        i += 1
    memo[(k, max_allowed)] = i
    return memo[(k, max_allowed)]


n = int(input())
GrundyTotal = 0
for i in range(n):
    k = int(input())
    GrundyTotal ^= Grundy(k, k)

print("YES" if GrundyTotal == 0 else "NO")
