word_a = input()
word_b = input()
n = len(word_a)

def sort_string(word):
    if len(word) == 1:
        return word
    left = sort_string(word[:len(word)//2])
    right = sort_string(word[len(word)//2:len(word)])
    return left+right if left < right else right+left

word_a = sort_string(word_a)
word_b = sort_string(word_b)
print("Yes" if word_a == word_b else "No")