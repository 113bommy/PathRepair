n= int(input())
if int(-(-n//1.08)*1.08) == n:
    print(int(n//1.08))
else:
    print(":(")