N = int(input())

ret = 0
i = 1
while (N - i) // i >= i :
  if (N - i) % i == 0 :
    ret += (N - i) // i
  i += 1

print(ret)