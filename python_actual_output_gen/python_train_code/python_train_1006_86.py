num = int(input())
count = 1
word_all = ''
while count <= num:
  word = input()
  word_all = word_all + word +  ','
  count = count + 1
while len(word_all) > 0:
  x = word_all[:word_all.find(',')]
  if len(x) < 10:
    print(x)
  else:
    x2 = x[0] + str(len(x[1:-1])) + x[-1]
    print(x2)
  x = ''
  word_all = word_all[word_all.find(',')+1:]