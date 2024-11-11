import re

interview = int(input())
speech = input()

speech = re.sub(r'o(go)*', '***', speech)
print(speech)

