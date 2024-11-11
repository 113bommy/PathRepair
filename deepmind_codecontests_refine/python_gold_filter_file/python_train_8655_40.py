s = str(input())
if (len(s) / 2 >= s.count('a')):
    print(s.count('a') * 2 - 1)
else: 
    print(len(s))