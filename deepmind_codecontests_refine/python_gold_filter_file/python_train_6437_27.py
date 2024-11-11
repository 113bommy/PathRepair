S = input()
l = len(S)
ans = l
"""
if len(set(list(S))) == 1 and S[0] == "0":
    print(0)
    exit()
"""
for i in range(l-1):
    if S[i] != S[i+1]:
        ans = min(ans,max(l-i-1,i+1))
print(ans)