s = input()
t = input()
m = len(s)
n = len(t)

x = 0
total = 0

repl = []
while x<(m-n+1):
    for y in range(n):
        if t[y] != s[x+y]:break
    else:
        x+=n
        total += 1
        continue
    x+=1
print (s)
