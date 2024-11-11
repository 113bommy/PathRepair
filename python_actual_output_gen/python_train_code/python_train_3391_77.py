n = int(input())
a=d=0
s = input()
for i in range(n):
    if s[i]=='A':
        a += 1
    else:
        d += 1
if a>d:
    print("Antoni")
elif d>a:
    print("Danik")
else:
    print("Friendship")