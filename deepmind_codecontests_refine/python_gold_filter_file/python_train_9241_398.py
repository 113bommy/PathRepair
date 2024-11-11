n=int(input())
a=input()
if len(a)<=n:
    print(a)
else:
    print(a[:n]+'...')