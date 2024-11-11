n = int(input())
if n == 1 or n == 2:
    print(1)
    print(n)
    exit(0)
i = 1
lst = []
while i < n:
    lst.append(i)
    if sum(lst) > n:
        lst.remove(lst[-1])
        lst.remove(lst[-1])
        lst.append(n - sum(lst))
    i += 1
print(len(lst))
for k in lst:
    print(k, end=" ")