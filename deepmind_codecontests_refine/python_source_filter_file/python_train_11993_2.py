s = input()
n = len(s)

mod = 10**9 + 7
fib = [1, 1]
for i in range(2, n+1):
    fib.append((fib[-1]+fib[-2])%mod)

ans, i = 0, 0
while True:
    x = s[i]
    if x == "w" or x == "m": print(0); exit()
    elif x == "u":
        cnt = 1
        for j in range(i+1, len(s)): 
            if s[j] == "u": cnt += 1
            else: break
        if cnt > 1:
            i = j
            ans += fib[cnt]
            ans %= mod
        else: i += 1
    elif x == "n":
        cnt = 1
        for j in range(i+1, len(s)): 
            if s[j] == "n": cnt += 1
            else: break
        if cnt > 1:
            i = j
            ans += fib[cnt]
            ans %= mod
        else: i += 1
    else:
        i += 1
    if i >= len(s): break

print(ans)