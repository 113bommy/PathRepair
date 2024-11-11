a, b =map(int, input().split())
s = set()
for i in range(a):
    li = input().split()
    for j in li:
        s.add(j)
print("#color" if 'C' in s or 'M' in s or 'Y' in s else "#Black&White")