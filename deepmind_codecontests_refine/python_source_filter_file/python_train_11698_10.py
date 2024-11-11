s = [[0, 0], [0, 0]]
for i in range(int(input())):
    server, pass_, down = map(int, input().split())
    s[server - 1][0] += pass_
    s[server - 1][1] += down
print('LIVE' if s[0][0] >= s[0][1] else 'DIED', 'LIVE' if s[1][0] >= s[1][1] else 'DIED', sep='\n')