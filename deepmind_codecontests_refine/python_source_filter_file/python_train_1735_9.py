n = int(input())
lst = list(map(int, input().split()))
ans = []
for i in range(n):
    for a in lst:
        if a * 2 in lst or (a % 3 == 0 and a // 3 in lst):
            continue
        else:
            ans.append(a)
            lst.remove(a)
print(', '.join([str(x) for x in ans[::-1]]))
