word1 = input()
word2 = input()

j = 1

for i in range(0,len(word1)):
    if word1[i] != word2[len(word2)-i-1]:
        j = 0
        
if j:
    print('YES')
    
else:
    print('NO')