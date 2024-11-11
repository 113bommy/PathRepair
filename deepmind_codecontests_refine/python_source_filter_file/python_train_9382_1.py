n = int(input())
aa = []
l = [*map(int ,input().split())]
for i in l:
     res = i % 2
     if not(len(aa)) or aa[-1] != res:
          aa.append(res)
     else:
          aa.pop(-1)
print("YES" if len(aa) >= 1 else "NO")
