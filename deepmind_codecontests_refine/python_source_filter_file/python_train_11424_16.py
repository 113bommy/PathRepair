word=input()
cword=word[len(word)//2:len(word)]
if word.count(word[0])==len(word):
    print('0')
elif word[0:len(word)//2]==cword[::-1]:
    print(len(word)-1)
else:
    print(len(word))
