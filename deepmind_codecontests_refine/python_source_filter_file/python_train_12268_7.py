from collections import Counter

N = int(input())
D = list(map(int, input().split()))
M = int(input())
T = list(map(int, input().split()))

c1 = Counter(D)
c2 = Counter(T)

for t in c2.keys():
    if c2[t] > c1[t]:
        print("No")
        exit()
print("Yes")