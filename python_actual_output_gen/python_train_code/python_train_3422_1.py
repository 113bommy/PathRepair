n=int(input())
array=set()
array.add(10**9)
for x in range(10):
    for y in range(10):
        for l in range(1, 9):
            for m in range(1, 2 ** l + 1):
                s = [str(x) if m & (1 << i) else str(y) for i in range(l)]
                u = int(''.join(s))
                if u <= n:
                    array.add(u)
array.remove(0)
# print (sorted(list(array)))
array=[u for u in array if u <= n]
print(len(array))