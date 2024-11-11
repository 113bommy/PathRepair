n = int(input())
k=input()
if len(k)>n:
    print(k[:n]+'...')
else:
    print(k)