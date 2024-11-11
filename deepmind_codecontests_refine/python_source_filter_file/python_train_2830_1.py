n = int(input())
s1 = input()
s2 = input()
ab = []
ba = []
for i in range(n):
    if s1[i] == 'a' and s2[i] == 'b':
        ab.append(i)
    elif s1[i] == 'b' and s2[i] == 'a':
        ba.append(i)
if (len(ab) + len(ba)) % 2:
    print(-1)
else:
    print(len(ab) // 2 + len(ba) // 2 + len(ab) % 2)
    for i in range(1, len(ab), 2):
        print(ab[i - 1] + 1, ab[i] + 1)
    for i in range(1, len(ba), 2):
        print(ba[i - 1] + 1, ba[i] + 1)
    if len(ab) % 2:
        print(ab[-1] + 1, ab[-1] + 1)
        print(ab[-1] + 1, ba[-1] + 1)