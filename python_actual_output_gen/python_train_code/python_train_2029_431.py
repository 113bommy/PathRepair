word1 = input()
word2 = input()

i = 1

for i in range(0,len(word1)):
    if word1[i] != word2[len(word2)-i-1]:
        i = 0
        
if i:
    print('YES')
    
else:
    print('NO')