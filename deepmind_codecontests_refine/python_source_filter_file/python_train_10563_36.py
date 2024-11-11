len_sentence, ln_words = map(int, input().split())

words = {}
for i in range(ln_words):
    lang1, lang2 = input().split()
    words[lang1] = lang1 if len(lang1) < len(lang2) else lang2

sentence = input().split()
written_sentence = []

for word in sentence:
    written_sentence.append(words[word])

print(" ".join(written_sentence))