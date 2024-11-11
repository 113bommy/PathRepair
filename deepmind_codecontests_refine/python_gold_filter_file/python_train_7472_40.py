import sys
input = lambda: sys.stdin.readline().rstrip()
N = int(input())
def I():
    s = input()
    mi = 0
    su = 0
    t = 0
    for a in s:
        if a == "(":
            t += 1
        else:
            t -= 1
            mi = min(mi, t)
    return (mi, t)

X = [I() for _ in range(N)]
if sum([x[1] for x in X]):
    print("No")
    exit()

X = sorted(X, key = lambda x: -10**10 if x[0] == 0 else -10**9 - x[0] if x[1] > 0 else x[0] - x[1])
T = 0
for mi, t in X:
    if T + mi < 0:
        print("No")
        exit()
    T += t
print("Yes")