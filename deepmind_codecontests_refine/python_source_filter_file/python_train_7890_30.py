import re
# イテレーションのため
input()
S = input()
K = int(input())

print(re.sub(r'[^%s]' %S[K] , '*', S))