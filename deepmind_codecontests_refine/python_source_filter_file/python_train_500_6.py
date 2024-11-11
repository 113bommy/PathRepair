from collections import Counter
s = input()
c,x = Counter(s).most_common(),len(s)
if any(c[i][1]-x//3-1 for i in range(x%3)) or any(c[i][1]-x//3 for i in range(x%3,3)): print("NO")
else: print("YES")