s = list(input())
if sorted(s, reverse=True) == s and len(s) == 26:
    print(-1)
    quit()
for i in range(1, 26+1):
    if chr(97 + i) not in s and len(s) != 26:
        print(''.join(s) + chr(97+i))
        quit()

while len(s) > 0:
    while ord(s[-1]) < ord('z'):
        s[-1] = chr(ord(s[-1])+1)
        if len(s) == len(set(s)):
            print(''.join(s))
            quit()
    del s[-1]