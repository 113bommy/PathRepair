s=input()
print('YNeos'[int(s)%sum([int(c) for c in s])==0::2])