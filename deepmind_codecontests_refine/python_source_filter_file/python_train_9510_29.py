# Little Elephant and Rozdill
n = int(input())
d = list(map(int, input().split()))
x = min(d)
if d.count(x) > 1:
    print("Still Rozdill")
else:
    print(d.index(x) + 1)
