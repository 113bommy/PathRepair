n=int(input())
a=set()
for i in range(n):
    s=input()
    while 'kh' in s:
        t=s.replace('kh','h')
        s=t
    t=s.replace('u','o')
    s=t
    a.add(s)
print(len(a))