x = input()
n = int(x.split(" ")[0])
s = int(x.split(" ")[1])

x = input()
x = x.split(" ")

arr = [int(i) for i in x]

if sum(arr)<s:
  print("-1")

else:
  imin = min(arr)
  x = (sum(arr) - s)//n
  print(max(imin, x))