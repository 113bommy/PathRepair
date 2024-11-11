s = input()
if s.count("9") == len(s):
    print(sum(map(int, s)))
else:
    print(int(s[0])-1 + 9*(len(s)-1))
