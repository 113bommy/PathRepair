s = list(input())
k = int(input())

for i in range(len(s)):
        if ord("z")-ord(s[i])+1<=k:
                k -= ord("z")-ord(s[i])+1
                s[i] = "a"
if k: s[-1] = chr((ord(s[-1])+k-ord("a"))%26+ord("a"))
print("".join(s))