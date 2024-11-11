a = input().lower()
b = input().lower()

a = list(a.split())
b = list(b.split())


for i,t in zip(a,b):
    if i > t:
        print(-1)
    elif i < t:
        print(1)
    else:
        print(0)
