from collections import Counter
T = int(input())
for _ in range(T):
    t = input()
    b = Counter(t)
    zero = b["0"]
    one = b["1"]
    
    if zero == 0 or one == 0:
        print(t)
    else:
        ans = "01"*(zero+one)
        print(ans)