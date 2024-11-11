N = int(input())
s = [int(input()) for _ in range(N)]
total = sum(s)
if total % 10 != 0:
    print(total)
    exit()

for si in s:
    if si % 10 != 0:
        print(total - si)
        exit()
print(0)