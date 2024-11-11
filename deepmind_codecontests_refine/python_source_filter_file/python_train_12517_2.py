n=input()
l="HQ9+"
d=0
for i in range(len(n)):
    if n[i] in l:
        d=1
        break
if d==1:
    print("YES")
else:
    print("NO")
