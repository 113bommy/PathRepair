import sys
input = sys.stdin.readline

a1 = input()
a2 = input()
ans = []
for i in range(len(a1) - 2):
    if a1[i:i + 1] == a2[i:i + 1]:
        ans.append(0)
    else:
        ans.append(1)
for i in ans:
    print(i, end = "")

