import statistics
while True:
  n = input()
  if n == '0': break
  print(statistics.stdev(map(int, input().split())))