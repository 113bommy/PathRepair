_1,__ = map(int, input().split())
s = []
n = 0

for i in map(int,input().split()):
    n += i
    s.append(i)

r = int(input())

if r>=_1 :
    print(n-((r-_1)*__))
elif r<_1 : 
    d=0
    s= sorted(s)
    for i in range(0, r):
        d += s[i]
    print(d)
    