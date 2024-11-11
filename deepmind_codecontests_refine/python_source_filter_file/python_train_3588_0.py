def main():
    home = input()
    away = input()
    n = int(input())
    fouls = {}
    yellowed = set()
    printed = set()
    for i in range(n):
        (t, team, m, color) = input().split(' ')
        fouls[int(t)] = (team, int(m), color)
    for t in range(1, 91):
        if t not in fouls:
            continue
        (team, m, color) = fouls[t]
        if (m, team) in printed:
            continue
        if color == 'r' or (m, team) in yellowed:
            if team == 'a':
                print(away, m, t)
            else:
                print(home, m, t)
        printed.add((m, team))
        yellowed.add((m, team))

main()
