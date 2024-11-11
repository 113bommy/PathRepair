s=input()
K=int(input())
S=[c for c in s]
def diff(c):
    return ord('z')-ord(c)
for i in range(len(s)):
    d=diff(S[i])
    if d<K:
        K-=d+1
        S[i]='a'
k=K%26
S[-1]=chr(ord(S[-1])+k) if k<=diff(S[-1]) else chr(ord(S[-1])+k-26)
print(''.join(S))