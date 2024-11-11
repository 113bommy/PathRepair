s = input()
x = sum(s.count(i) % 2 for i in s)
if x % 2+(x < 1)==0:
    print("First")
else:
    print("Second")