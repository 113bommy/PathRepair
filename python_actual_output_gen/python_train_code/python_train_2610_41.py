info_dict = {abc:list(input()) for abc in 'abc'}
choice = 'a'

while info_dict[choice]:
  choice = info_dict[choice].pop()
  
print(choice.upper())