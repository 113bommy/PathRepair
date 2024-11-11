n = int(input())
s = input()
d = []
for i in range(1, n+1):
    if n % i == 0:
        d.append(i)
for c in d:
    s = s[c-1::-1]+s[c::]
    print(s)
