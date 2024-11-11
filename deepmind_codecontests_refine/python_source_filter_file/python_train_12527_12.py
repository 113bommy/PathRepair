s = input()

words = s.split('.')
n = s.count('.')
numberOfWordsWithSizeLessThanTwo = len([x for x in words[1:-1] if len(x) < 2])
numberOfWordsWithSizeMoreThanEleven = len([x for x in words[1:-1] if len(x) > 11])

if len(words) == 1:
    print('NO')
elif len(words[0]) < 1 or len(words[0]) > 8 or len(words[-1]) < 1 or len(words[-1]) > 3 or numberOfWordsWithSizeLessThanTwo != 0 or numberOfWordsWithSizeMoreThanEleven != 0:
    print('NO')
else:
    s0 = words[0]
    sn = words[-1]
    s1 = ''
    s2 = ''
    print('YES')
    
    for word in words[1:-1]:
        if len(word) > 10:
            s2 = word[-8:]
            s1 = word[:-8]
        else:
            s1 = word[0]
            s2 = word[1:]
        res = s0 + '.' + s1
        print(res)
        s0 = s2
    print(s0 + '.' + sn)
    

# print(words, len(words), n, numberOfWordsWithSizeLessThanTwo, numberOfWordsWithSizeMoreThanEleven)
# print(words[1:-1])




