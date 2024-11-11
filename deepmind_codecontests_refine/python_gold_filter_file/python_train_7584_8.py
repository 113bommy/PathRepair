dic = {i:list(input()) for i in 'abc'}
key = 'a'
while len(dic[key]) != 0:
  key = dic[key].pop(0)
print(key.upper())