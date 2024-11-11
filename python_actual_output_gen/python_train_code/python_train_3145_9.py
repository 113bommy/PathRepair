n = int(input())
list = input().split(" ")

for i in range(len(list)):
  list[i] = int(list[i])

list = sorted(list)

currentFreq = 0
currentMaxFreq = 1

for i in range(1,n):
  if list[i] == list[i-1]:
    currentFreq += 1
  else:
    currentFreq = 1
  if currentFreq > currentMaxFreq:
    currentMaxFreq = currentFreq
print(currentMaxFreq)