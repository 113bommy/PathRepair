s=input()
a=0
for x in s:
    if ord(x)-97-a>1: print('NO'); break
    else: a=max(a,ord(x)-97)
else: print('YES')