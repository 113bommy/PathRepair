n,k,c = map(int,input().split())
sl = list(input())

# 前貪欲
ansl = []
before = -float("inf")
for idx,s in enumerate(sl):
    if s == "o" and before + c < idx:
        before = idx
        ansl.append(idx)

if len(ansl) > k:
    print()
    exit()
# 後貪欲
ansl2 = []
before = -float("inf")
for idx,s in enumerate(sl[::-1]):
    if s == "o" and before + c < idx:
        before = idx
        ansl2.append(n-idx-1)

for a in list(set(ansl) & set(ansl2)):
    print(a+1)