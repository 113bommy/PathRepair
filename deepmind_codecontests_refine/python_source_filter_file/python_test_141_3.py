for i in range(int(input())):
  a, s = input().split()
  a, s = a[::-1], s[::-1]
  na = len(a)
  ns = len(s)
  ans = ''
  k = 0
  flag = True
  for j in range(na):
    if k >= ns:
      flag = False
      break
    a_int = int(a[j])
    s_int = int(s[k])
    if a_int <= s_int:
      ans += str(s_int - a_int)
      k += 1
    else:
      if k + 1 >= ns:
        flag = False
        break
      else:
        s_int2 = int(s[k + 1] + s[k])
        if s_int2 // 10 != 1:
          flag = False
          break
        else:
          ans += str(s_int2 - a_int)
          k += 2

  if flag:
    print(int(s[:ns - k][::-1] + ans[::-1]))
  else:
    print(-1)