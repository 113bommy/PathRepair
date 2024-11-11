s=[input() for _ in range(int(input()))]
t=[input() for _ in range(int(input()))]
cnt=[0]*(len(s)+1)
for i in range(len(s)):
    cnt[i]=s.count(s[i])-t.count(t[i])
print(max(cnt))

