a=input()
b=input()
if len(a)==len(b):
    print("NO")
else:
    if a==b:
        print("YES")
    elif a.count("0")==len(a) or b.count("0")==len(b):
        print("NO")
    else:
        print("YES")