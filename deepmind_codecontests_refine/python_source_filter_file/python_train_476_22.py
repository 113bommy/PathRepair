s = list(map(int, input().split()))
a = s[0]*s[1]+2*s[2]
b = s[0]*s[2]+2*s[4]
if a == b: print("Friendship")
elif a > b: print("First")
else: print("Second")