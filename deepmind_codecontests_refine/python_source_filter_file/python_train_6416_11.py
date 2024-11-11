n=int(input())
if n%10<=5:
    print(n-(n%5))
else:
    print(n+(10-n%5))
