n = int(input())+1
#l = list(map(int, input().strip().split(' ')))
import collections

if collections.Counter(str(n))['0']+1 == len(str(n)):
    print(1)
else:
    next_number = int(str(int(str(n)[0])+1) + '0'*(len(str(n))-1))
    print(next_number-n+1)