n = int(input())
l1 = list(input())
if len(set(l1))>=2:
    print("YES")
    print("".join(list(set(l1))[:2]))
else:
    print("NO")
