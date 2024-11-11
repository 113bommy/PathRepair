word = list(input())
def poop(word):
    correct = ['A','H','I','M','O','T','U','V','W','X','Y']
    for i in word:
        if i not in correct:
            return "NO"
    if reversed(word) == word:
        return "YES"
    return "NO"
print(poop(word)) 