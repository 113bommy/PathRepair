# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')


n = int(input())
a = list(map(int, input().split()))

ans = 0
counts = {}
for el in a:
    counts[el] = counts.get(el, 0) + 1

for el in a:
    found = False
    for i in range(31):
        tgt = pow(2, i)
        if tgt > el:
            if tgt - el == el:
                if tgt - el in counts and counts[tgt-el] > 1:
                    found = True
                    break
            elif tgt -el in counts:
                found = True
                break
    if not found: ans += 1
print(ans)