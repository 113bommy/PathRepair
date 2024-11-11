S = list(input())
if "R" not in S[0::2] and "L" not in S[1::2]:
    print ("Yes")
else:
    print("No")