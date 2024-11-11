a = list(map(int, input().split()))
servers = []
commands = []
output = []
for i in range(a[0]):
    temp = list(map(str, input().split()))
    servers.append(temp)
for i in range(a[1]):
    temp = list(map(str,input().split()))
    temp[1] = temp[1][:len(temp[1])-1]
    commands.append(temp)
for i in range(a[1]):
    for j in range(a[0]):
        if servers[j][1] == commands[i][1]:
            output.append(commands[i][0] + ' ' + commands[i][1] + ' #' + servers[j][0])
for i in output:
    print(i)
