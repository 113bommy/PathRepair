n = int(input())
lis = set()
for i in range(n):
    a = int(input())
    if a not in lis:lis.add(a)
    else:lis.remove(a)
print(len(lis))