n = int(input())
d = [int(item) for item in input().split()]
ds = []
ans = []
for i, item in enumerate(d):
    ds.append((item, i))
ds.sort(reverse=True)
max_dist = ds[0][0]
max_idx = ds[0][1]

to_fill = max_dist - 1

ans = [[] for _ in range(max_dist+1)]
ans[0].append(max_idx*2+1)
ans[max_dist].append(max_idx*2+2)

itr = 0
for dist, idx in ds[1:]:
    if to_fill == 0:
        break
    itr += 1
    odd = idx*2+1
    ans[itr].append(odd)
    to_fill -= 1


to_fill = max_dist - 1
itr = 0
for dist, idx in ds[1:]:
    odd = idx*2+1
    even = idx*2+2
    if to_fill > 0:
        itr += 1
        if itr + dist == len(ans):
            ans.append([even])
        else:
            ans[itr+dist].append(even)
    else:
        if dist == 1:
            ans.append([odd])
            ans.append([even])
        else:
            ans[0].append(odd)
            ans[dist-2].append(even)
    to_fill -= 1

prev_par = None
for line in ans:
    par = line[0]
    if prev_par is not None:
        print(prev_par, par)
    for item in line[1:]:
        print(par, item)
    prev_par = par