a = []
a = list(map(int, input().split()))
n = a[0]
m = a[1]
mymap = {}
commands = []
for i in range(0, n):
    vin = list(input().split())
    mymap[(vin[1])] = vin[0]
for i in range(0, m):
    command = input().strip(';')
    commands.append(command)
for i in range(0, m):
    command = commands[i];
    ip = list(command.split())[1]
    output = (commands[i]) + ' #' + (mymap[ip])
    print(output)