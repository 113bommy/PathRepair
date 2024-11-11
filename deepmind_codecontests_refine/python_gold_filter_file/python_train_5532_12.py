n=int(input())
four=str(n).count("4")
seven=str(n).count("7")
total=four+seven
if total==4 or total==7:
    print("YES")
else:
    print("NO")
    