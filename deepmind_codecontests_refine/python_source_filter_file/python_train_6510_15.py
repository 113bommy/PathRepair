from operator import itemgetter
from collections import defaultdict
_ = input()
lang = defaultdict(int)
for l in input().split(' '):
    lang[l] += 1
_ = input()
audio = input().split(' ')
subtitle = input().split(' ')
movie = []
for i, t in enumerate(zip(audio, subtitle)):
    a, s = t
    movie.append([lang[a], lang[s], i])
movie.sort(key=itemgetter(1, 2))
print(movie[0][-1] + 1)