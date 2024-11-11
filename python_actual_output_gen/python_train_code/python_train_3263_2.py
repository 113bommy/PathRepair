N = int(input())
S = sorted([int(input()) for _ in range(N)])
s = sum(S)
if s % 10 != 0:
    print(s)
    exit()

for si in range(S):
    if si % 10 != 0:
        print(s - si)
        exit()

print(0)
