n = int(input())
for _ in range(n):
    s = input()
    groupings = []
    current = s[0]
    for i in range(1, len(s)):
        if current[-1] == s[i]:
            current += s[i]
        else:
            groupings.append(current)
            current = s[i]
    groupings.append(current)
    groupings = [u[0] for u in groupings if len(u) % 2 == 1]
    print (''.join(sorted(list(set(groupings)))))