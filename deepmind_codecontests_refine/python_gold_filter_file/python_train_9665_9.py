n=int(input())
s=set()
for i in range(n):
    a=int(input())
    if a in s:
        s.remove(a)
    else:
        s.add(a)
print(len(s))