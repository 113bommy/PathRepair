a=int(input())
b=input()
if len(b)>=a:
    print(b[:a]+'...')
else:
    print(b)