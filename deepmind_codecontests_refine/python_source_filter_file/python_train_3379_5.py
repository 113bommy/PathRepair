a=int(input())
b=input().split()
b+=input().split()
b=list(set(b))
if "0" in b:
    b.remove("0")
b.sort()
if len(b)<a:
    print("Oh, my keyboard!")
else:
    print("I become the guy.")
