N, A, B, C = map(int, input().split())
S = [list(input()) for i in range(N)]

v = [A, B, C]
id_d = {'A':0, 'B':1, 'C':2}
ans = [0] * N
for i, s in enumerate(S):
  s1, s2 = s
  id1, id2 = id_d[s1], id_d[s2]
  v1, v2 = v[id1], v[id2]
  if v1 == v2 == 0:
    if i == 0:
      print('No')
      quit()
    else:
      pre_s1, pre_s2 = S[i-1]
      pre_id1, pre_id2 = id_d[pre_s1], id_d[pre_s2]
      if pre_s1 in [s1, s2]:
        v[pre_id1] += 2
        v[pre_id2] -= 2
        ans[i-1] = pre_s1
        if v[pre_id2] < 0:
          print('No')
          quit()
      else: # pre_s2 in [s1, s2]
        v[pre_id2] += 2
        v[pre_id1] -= 2
        ans[i-1] = pre_s2
        if v[pre_id1] < 0:
          print('No')
          quit()
  v1, v2 = v[id1], v[id2]
  if v1 >= v2:
    ans[i] = s2
    v[id1] -= 1
    v[id2] += 1
  else:
    ans[i] = s1
    v[id1] += 1
    v[id2] -= 1

print('Yes')
print(*ans, sep='\n')