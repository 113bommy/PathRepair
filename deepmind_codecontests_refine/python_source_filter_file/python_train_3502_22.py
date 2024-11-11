n, m = map(int, input().split())
server = {}
for _ in range(n):
    name, ip = input().split()
    server[ip] = name
command = [x for _ in range(m) for x in input().split("\n")]
for x in command:
    cmd, ip = x.split()
    for key in server.keys():
        if key == ip:
            print(x,"#"+server[key])
            break