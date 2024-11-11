s=input().rstrip()
t=set()
for i in s:
    t.add(i)
if len(t)%2==0:
    print('IGNORE HIM!')
else:
    print('CHAT WITH HER!')