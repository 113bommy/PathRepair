power = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824]

t = int(input())
for _ in range(t):
  n = int(input())
  if n == 2:
    print(power[1]-power[0])
  else:
    a = power[n-1]
    counta = 1
    for i in range(0,n//2):
      if counta != n//2:
        # print(a,power[i])
        a += power[i]
        counta += 1
    # print(a)
    b = 0
    i += 1
    while i < n:
      # print(power[i])
      b += power[i]
      # print(power[i])
      i += 1

    # print(a,b)
    print(abs(a-b))