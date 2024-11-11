n=int(input())
a=set()
for i in range(n):
    b=int(input())
    if b in a:
        a.remove(b)
    else:
        a.add(b)
print(len(a)) 