from collections import Counter
alph = 'abcdefghijklmnopqrstuvwxyz'.upper()

s = input()
ans = ''
for i in range(len(s)-25):
    subs = s[i:26+i]
    d = Counter(subs)
    del d['?']
    if all(x == 1 for x in d.values()):
        subs = list(subs)
        for c in alph:
            if c in subs: continue
            else:
                subs[subs.index('?')] = c
        subs = ''.join(subs)
        ans = s[:i] + subs + s[26+i:]
        ans.replace('?', 'A')
        break

print(-1 if not ans else ans)

