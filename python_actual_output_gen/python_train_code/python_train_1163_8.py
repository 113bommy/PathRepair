a=int(input())
b=input().split()[1:]
b+=input().split()[1:]
b=list(set(b))
if "0" in b:
    b.remove("0")
b.sort()
if len(b)<a:
    print("Oh, my keyboard!")
else:
    print("I become the guy.",b)