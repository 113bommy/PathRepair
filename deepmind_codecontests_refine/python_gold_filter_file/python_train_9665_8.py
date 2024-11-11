N = int(input())
s = set()
for i in range(N):
    s ^= {int(input())}
print(len(s))
