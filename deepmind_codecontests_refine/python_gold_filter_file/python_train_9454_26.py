N = int(input())
for i in range(1,N+2):
  if i*(i-1)//2==N:
    print('Yes')
    ans = [[] for i in range(i)]
    cnt = 0
    p = 0
    q = 1
    while cnt<N:
      cnt += 1
      ans[p].append(cnt)
      ans[q].append(cnt)
      if q==i-1:
        p += 1
        q = p+1
      else:
        q += 1
    print(len(ans))
    for a in ans:
      print(len(a),*a)
    break
else:
  print('No')