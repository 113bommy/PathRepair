s=(input())
t=s.count('a')
u=len(s)-t
if t>=u:
    print(t+u)
else:
    print(abs(t-u))