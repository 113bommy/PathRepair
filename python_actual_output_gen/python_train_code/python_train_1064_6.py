p = []
for _ in range(int(input())):
    s,c = input().split()

    f = s+c
    if f not in p:
        p.append(f)
print(len(p))