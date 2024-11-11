from collections import Counter
host = input()
guest = input()
shuffle = input()
string = host + guest
count1 = Counter(string)
count2 = Counter(shuffle)
if count1 == count2:
    print('YES')
else:
    print('No')