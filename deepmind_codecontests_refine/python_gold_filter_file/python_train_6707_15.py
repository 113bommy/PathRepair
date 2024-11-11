t = {i: 0 for i in 'qwertyuiopasdfghjklzxcvbnm'}
for i in input(): t[i] += 1
print(min([t['i'], t['t'], t['e'] // 3, max(0, (t['n'] - 1)) // 2]))