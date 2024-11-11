n = int(input())
d = {}

for _ in range(n):
    s = input()
    if s in d:
        d[s] += 1
    else:
        d[s] = 1

d = sorted(d.items(), key = lambda x: x[1])
if len(d) == 2:
    for i in range(len(d)-1):
        if d[i][1] == d[i+1][1]:
            print("YES")
            print(d[i][0], d[i+1][0])
            break
    else:
        print("NO")
else:
    print("NO")
    
