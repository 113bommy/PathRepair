suffixes = {'po' : 'FILIPINO', 'desu' : 'JAPANESE', 'masu' : 'JAPANESE', 'MNIDA' : 'KOREAN'}
sentences = []

for i in range(int(input())):
    sentences.append(input())

for i in range(len(sentences)):
    for suffix, language in suffixes.items():
        if sentences[i][-len(suffix):] == suffix:
            print (language)
            break