a = input()
b = set()
c = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q' ,'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
for i in c:
    for j in range(len(a) + 1):
        b.add(a[:j] + i + a[j:])
print(b)
print(len(b))
