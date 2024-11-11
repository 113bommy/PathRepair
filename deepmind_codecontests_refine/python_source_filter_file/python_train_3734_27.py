w = input()
if all([w.count(s) % 2 == 0 for s in set(w)]):
    print("YES")
else:
    print("No")