from collections import Counter

c = Counter(input())
if len(c) <= 1 or len(c) >= 5:
    print("No")
elif len(c) == 4:
    print("Yes")
elif len(c) == 2 and min(c.values()) >= 2:
    print("Yes")
elif len(c) == 3 and c.most_common(2)[0][1] >= 2:
    print("Yes")
else:
    print("No")
