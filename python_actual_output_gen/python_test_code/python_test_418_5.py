# B. Decoding

n = int(input())
s = input()

# Idea from https://codeforces.com/contest/746/submission/73997188
print(s[-2::-2])
print(s[-1::-2][::-1])
