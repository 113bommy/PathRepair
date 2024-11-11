t = int(input())

cases = []
for i in range(t):
    n,k=map(int, input().strip().split())
    cases.append((k, list(map(int, input().strip().split()))))

def solve(case):
    k, b = case
    b.sort()
    if k == 0:
        return b[-1]-b[0]
    else:
        return sum(b[-k-1:])


for case in cases:
    print(solve(case))
