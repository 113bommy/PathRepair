import sys

serverTraffic = 0
activeUsers = 0

for line in sys.stdin:
    if line[0] == '+':
        activeUsers += 1
    elif line[0] == '-':
        activeUsers -= 1
    else:
        serverTraffic += (activeUsers - 1) * (len(line) - line.find(':') - 1)
        #serverTraffic += activeUsers * (len(line) - line.find(':') - 2)

print(serverTraffic)