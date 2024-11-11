import sys
trafic = 0
s = set()
for request in sys.stdin:
    if request[0] == "+":
        s.add(request[1:])
    elif request[0] == "-":
        s.remove(request[1:])
    else:
        trafic += len(request[request.find(":"):])*len(s)
print(trafic)