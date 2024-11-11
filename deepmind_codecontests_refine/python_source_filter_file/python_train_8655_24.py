l = input()
if(l.count('a')>len(l)//2):
    print(l.count('a'))
else:
    print(2*l.count('a')-1)