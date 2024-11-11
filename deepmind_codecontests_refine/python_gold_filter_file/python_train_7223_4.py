n = int(input())
for i in range(n):
    a = input()
    if a[:5] == "miao." and a[len(a)-5:] == "lala.":
        print("OMG>.< I don't know!")
    elif a[len(a)-5:] == "lala.":
        print("Freda's")
    elif a[:5] == "miao.":
        print("Rainbow's")
    else:
        print("OMG>.< I don't know!")
    