#091_B
n=int(input())
s=[input() for _ in range(n)]
m=int(input())
t=[input() for _ in range(m)]

res=0
for S in set(s):
    res+=max(0,s.count(S)-t.count(S))
print(res)