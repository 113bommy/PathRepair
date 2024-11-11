from sys import stdin
input=stdin.readline
voiceEmail = input()
dotReplaced = voiceEmail[1:len(voiceEmail) - 2].replace('dot', '.')
voiceEmail = voiceEmail[0] + dotReplaced + voiceEmail[len(voiceEmail) - 2:]
atReplaced = voiceEmail[1:len(voiceEmail) - 2].replace('at', '@', 1)
voiceEmail = voiceEmail[0] + atReplaced + voiceEmail[len(voiceEmail) - 2:]
print(voiceEmail)