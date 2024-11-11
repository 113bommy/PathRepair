dic = {i:list(input()) for i in 'abc'}
key = 'a'
while len(dic[key]) != 0:
  key = dic.pop(key)
print(key.upper())