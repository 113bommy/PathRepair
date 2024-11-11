from sys import stdin, stdout

q = int(stdin.readline())

while q != 0:
  n = int(stdin.readline())

  ans2, ans3, ans5 = 0, 0, 0
  while n % 5 == 0:
    n /= 5
    ans5 += 1
    ans2 += 2
  
  while n % 3 == 0:
    n /= 3
    ans2 += 1
    ans3 += 1

  while n % 2 == 0:
    n /= 2
    ans2 += 1
  
  if n > 1:
    print(-1)
  else:
    print(int(ans2 + ans3 + ans5))
  
  q -= 1
