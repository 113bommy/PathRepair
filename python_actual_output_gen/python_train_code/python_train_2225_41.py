S = input()
c0 = S[len(S)//2]
r = S.find("1" if c0 == "0" else "0", len(S)//2)
if r < 0: r = len(S)//2
l = S.rfind("1" if c0 == "0" else "0", 0, len(S)//2)
l += 1
K = min(r, len(S)-l)
#print(l, r, K)
print(K)
