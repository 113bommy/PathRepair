def twopoly(m,n):
    if m%n == 0:
        return "YES"
    else:
        return "NO"

cases = int(input())
for _ in range(cases):
    m,n = list(map(int,input().split()))
    print(twopoly(m,n))
    