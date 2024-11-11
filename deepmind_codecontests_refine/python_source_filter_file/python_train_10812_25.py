S = list(input())
K = int(input())
a = ord("a")
for i,s in enumerate(S):
    t = a-ord(s)+26
    if K>=t:
        K-=t
        S[i] = "a"
if K>0:
    S[-1] = chr(a + (ord(S[-1])-a+K)%26)
print("".join(S))