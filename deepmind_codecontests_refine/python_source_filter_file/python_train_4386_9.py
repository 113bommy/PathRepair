input()
napis = input()

for i in range(len(napis)):
  if i > 0:
    if(napis[i] < napis[i-1]):
      napis = napis[:i-1] + napis[i:]
      break
  if i == len(napis) - 1:
    napis = napis[1:]

print(napis)