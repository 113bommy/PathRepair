n = int(input())
lis = []
for i in range(n):
    a = int(input())
    if a not in lis:lis.append(a)
    else:lis.remove(a)
print(len(lis))