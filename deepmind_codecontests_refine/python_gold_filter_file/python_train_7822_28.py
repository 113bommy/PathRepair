from collections import deque

n = int(input())
a = map(int, input().split())


d = deque(a, n)

r = ""
t = 0
while len(d) > 0 :
    if t < d[0] < d[-1]:
        r += "L"
        t = d.popleft()
    elif t < d[-1]:
        r += "R"
        t = d.pop()
    elif t < d[0]:
        r += "L"
        t = d.popleft()
    else:
        break

    #print(t, d)

print(len(r))
print(r)