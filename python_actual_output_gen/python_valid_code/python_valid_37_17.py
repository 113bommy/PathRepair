n= int(input())
if int(-(-n//1.08)*1.08) == n:
    print(n//1.08)
else:
    print(":(")