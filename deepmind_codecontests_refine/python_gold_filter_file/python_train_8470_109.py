s = str(int(input())+1)
l = len(s)
while(len(set(s))!=l):
    s = str(int(s)+1)
print(s)