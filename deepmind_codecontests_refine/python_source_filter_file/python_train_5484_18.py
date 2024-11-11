def substring_sort():
    k = int(input())
    team = []
    for i in range(k):
        sub = input()
        team.append(sub)
    team.sort(key = len)
    for i in range(k-1):
        if team[i] not in team[i+1]:
            print("NO")
            return
    print("Yes")
    print('\n'.join(team))
    return
substring_sort()

