n,k,c = map(int,input().split())
sl = list(input())

# 前貪欲
ansl = []
before = -float("inf")
for idx,s in enumerate(sl):
    if s == "o" and before + c < idx:
        before = idx
        ansl.append(idx)

# 後貪欲
ansl2 = []
before = -float("inf")
for idx,s in enumerate(sl[::-1]):
    if s == "o" and before + c < idx:
        before = idx
        ansl2.append(n-idx-1)



for a1,a2 in zip(ansl[:k], ansl2[::-1][:k]):
    if a1 == a2:
        print(a1+1)
