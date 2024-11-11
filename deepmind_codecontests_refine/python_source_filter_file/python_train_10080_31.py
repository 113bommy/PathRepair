s = input()
K=int(input())

subs = set()
L = len(s)
for l in range(1,L+1):
    for i in range(L-l+1):
        subs.add(s[i:i+l])
print(sorted(list(subs))[K-1])