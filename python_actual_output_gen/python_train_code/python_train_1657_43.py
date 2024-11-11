s=input()
t=input()

if sorted(s)[::-1]<sorted(t)[::-1]:
    print('Yes')
else:
    print('No')