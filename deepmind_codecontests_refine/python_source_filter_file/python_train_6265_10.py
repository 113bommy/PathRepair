n = int(input())
s = input()
bal = 0
worst = 0
for i in s:
    if i=="(":
        bal+=1
    else:
        bal-=1
    worst = min(bal,worst)

if not bal:
    print("NO")
else:
    print("YES" if worst>=-1 else "NO")