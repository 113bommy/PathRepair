l = input()
if(l.count('a')>len(l)//2):
    print(len(l))
else:
    print(2*l.count('a')-1)