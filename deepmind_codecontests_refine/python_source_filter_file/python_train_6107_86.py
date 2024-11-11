n=input()
if len(n)>0:
    if "1111111" in n:
        print("YES")
    elif "00000000" in n:
        print("YES")
    else:
        print("NO")