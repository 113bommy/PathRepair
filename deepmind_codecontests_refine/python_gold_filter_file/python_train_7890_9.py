import re
N = int(input())
S = input()
K = int(input())
print(re.sub('[^'+S[K-1]+']', '*', S))