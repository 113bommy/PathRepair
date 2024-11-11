t = int(input())
for i in range(t):
    n = int(input())
    s = input()
#    k = n - 11
#    if s.find('8') == -1:
#        print("NO")
#    elif s.find('8') <= k:
#        print("YES")
#    else:
#        print("NO")
print("YES" if "8" in s[:-10] else "NO")
