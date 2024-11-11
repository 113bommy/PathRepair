# cook your dish here
s = []
t = []
inp = input().split()
n = int(inp[0])
m = int(inp[1])
for i in range(n):
    k = input()
    s.append(k)
for i in range(m):
    k = input()
    t.append(k)
for i in range(m):
    it = t[i].split(' ')[1][:-1]
    for j in range(n):
        if it == s[j].split(' ')[1]:
            t[i] = t[i] + ' '+'#'+ s[j].split(' ')[0]

for i in range(i):
    print(t[i])