n = int(input())
a = list(map(int,input().split()))

s = set()
for i in a:
    s.add(i)

if len(s) == 1 or len(s) == 2:
    print("YES")

elif len(s) == 3:
    for i in s:
        if i != max(s) and i != min(s):
            num = i
    if max(s) + min(s) == 2*num:
        print("YES")
    else:
        print("NO")
else:
    print("NO")
