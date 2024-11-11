n, k = input().split(' ')
n = int(n)
k = int(k)
s = list(input())
d = dict()
for i in range(ord('a'), ord('z')+1):
  d[chr(i)] = 0
for elem in s:
  d[elem] += 1


for i in range(ord('a'), ord('z')+1):
  l = chr(i)
  if d[l] <= k:
    k -= d[l]
  else:
    break

st = []
count = 0
for elem in s:
  if elem > l:
    st.append(elem)
  elif elem == l:
    if count >= k:
      st.append(elem)
    else:
      count += 1
print(''.join(st))
