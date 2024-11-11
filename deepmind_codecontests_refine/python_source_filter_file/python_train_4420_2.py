a=input()[1:-1].replace(" ", "").split(",")
if len(a)==1:
    print("0")
else:
    print(len(set(a)))