import sys

n = sys.stdin.readline()
S = sys.stdin.readline().split()
maxanswer = 0
for word in S:
    answer = 0
    for character in word:
        if ord(character) > 64 and ord(character) < 91:
            answer += 1
        else:
            pass

    maxanswer = max(answer, maxanswer)

print(answer)
