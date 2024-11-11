t = int(input())
for _ in range(t):
  n, m, k = map(int, input().split())
  if n%2 == m%2 == 0:
    if k%2 == 0:
      print("YES")
      ans = [[0]*(m+2) for _ in range(n+2)]
      cnt = 0
      j = 1
      moji= 0
      while cnt < k:
        for i in range(1, n+1):
          while ans[i-1][j] == chr(97+moji%26) or ans[i][j-1] == chr(97+moji%26):
            moji += 1
          ans[i][j] = chr(97+moji%26)
          ans[i][j+1] = chr(97+moji%26)       

          cnt += 1
          if cnt == k:
            break
        j += 2
      
      i = 1
      while i < n+1:
        for j in range(1,m+1):
          if ans[i][j] == 0:
            while ans[i-1][j] == chr(97+moji%26) or ans[i][j-1] == chr(97+moji%26) or ans[i+1][j-1] == chr(97+moji%26):
              moji += 1
            ans[i][j] = chr(97+moji%26)
            ans[i+1][j] = chr(97+moji%26)

        i += 2

      for x in ans[1:n+1]:
        print("".join(x[1:m+1]))
    else:
      print("NO")

  elif n%2 == 0:
    if (n*m - 2*k)//2 - n//2 >= 0 and ((n*m - 2*k)//2 - n//2)%2==0:
      print("YES")
      ans = [[0]*(m+2) for _ in range(n+2)]
      i = 1
      moji = 0
      while i <= n:
        while ans[i-1][1] == chr(97+moji%26):
          moji += 1
        ans[i][1] = chr(97+moji%26)
        ans[i+1][1] = chr(97+moji%26)     
        i += 2

      K = (n*m - 2*k)//2 - n//2
      cnt = 0
      i = 1
      while cnt < K:
        for j in range(2, m+1):
          while ans[i-1][j] == chr(97+moji%26) or ans[i][j-1] == chr(97+moji%26):
            moji += 1
          ans[i][j] = chr(97+moji%26)
          ans[i+1][j] = chr(97+moji%26)       

          cnt += 1
          if cnt == K:
            break
        i += 2
      
      for i in range(1, n+1):
        for j in range(1, m+1):
          if ans[i][j] == 0:
            while ans[i-1][j] == chr(97+moji%26) or ans[i][j-1] == chr(97+moji%26) or ans[i-1][j+1] == chr(97+moji%26):
              moji += 1
            ans[i][j] = chr(97+moji%26)
            ans[i][j+1] = chr(97+moji%26)

      for x in ans[1:n+1]:
        print("".join(x[1:m+1]))

    else:
      print("NO")

  else:
    if k - m//2 >= 0 and  (k-m//2)%2 == 0:
      print("YES")
      ans = [[0]*(m+2) for _ in range(n+2)]
      j = 1
      moji = 0
      while j <= m:
        while ans[1][j-1] == chr(97+moji%26):
          moji += 1
        ans[1][j] = chr(97+moji%26)
        ans[1][j+1] = chr(97+moji%26)     
        j += 2
      
      k = k - m//2
      cnt = 0
      j = 1
      while cnt < k:
        for i in range(2, n+1):
          while ans[i-1][j] == chr(97+moji%26) or ans[i][j-1] == chr(97+moji%26):
            moji += 1
          ans[i][j] = chr(97+moji%26)
          ans[i][j+1] = chr(97+moji%26)       

          cnt += 1
          if cnt == k:
            break
        j += 2
      
      i = 2
      while i < n+1:
        for j in range(1,m+1):
          if ans[i][j] == 0:
            while ans[i-1][j] == chr(97+moji%26) or ans[i][j-1] == chr(97+moji%26) or ans[i+1][j-1] == chr(97+moji%26):
              moji += 1
            ans[i][j] = chr(97+moji%26)
            ans[i+1][j] = chr(97+moji%26)

        i += 2

      for x in ans[1:n+1]:
        print("".join(x[1:m+1]))
    else:
      print("NO")