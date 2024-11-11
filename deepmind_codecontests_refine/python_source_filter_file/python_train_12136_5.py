n = int(input())
l = input()
r = []
for i in range(n):
    if i%2 == 0: r.append(l[i])
    else: r.insert(0, l[i])
print(''.join(r))


