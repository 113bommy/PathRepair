input()
a = [int(x) for x in input().split()]
l = min(a)
if (a.count(l) > 1):
    print("Still Rozdil")
else:
    print(a.index(l)+1)