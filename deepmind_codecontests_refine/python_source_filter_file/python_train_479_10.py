import collections
n = int(input())
a = list(map(int, input().split()))
s = 0
mp = {}
ans = 0
cnt = 0
for i in a:
    if(mp.get(i - 1) == None):
        mp[i - 1] = 0
    if(mp.get(i + 1) == None):
        mp[i + 1] = 0
    if(mp.get(i) == None):
        mp[i] = 0
    mp[i] += 1
    cnt += 1
    s += i
    ans += s - (i - 1) * mp[i - 1] - (i + 1) * mp[i + 1] - i * (cnt - mp[i-1] - mp[i + 1])
    #print(ans, (i - 1) * mp[i - 1] , (i + 1) * mp[i + 1] , i * cnt, i)
print(ans)