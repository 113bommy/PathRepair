n = int(input())
a = [int(input()) for _ in range(n)]
l = sorted(a)
print(l)
for i in a:
    if l[-1] == i:
        print(l[-2])
    else:
        print(l[-1])