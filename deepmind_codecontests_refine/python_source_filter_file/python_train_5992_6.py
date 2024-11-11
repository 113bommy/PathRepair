n = int(input())
a = list(map(int, input().split()))
lst = [[] for i in range(101)]
s = sum(a)
s = s // (n // 2)
for i in range(n):
    lst[a[i]].append(i)
for i in range(1, s // 2):
    if len(lst[i]) != 0:
        for j in range(len(lst[i])):
            print(min(lst[i][j], lst[s-i][j]) + 1, max(lst[i][j], lst[s-i][j]) + 1)
if s % 2 == 0 and len(lst[s//2]) != 0:
    for i in range(0, len(lst[s//2])-1, 2):
        print(lst[s//2][i] + 1, lst[s//2][i+1] + 1)
