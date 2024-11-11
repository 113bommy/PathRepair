s = input()
a = [s.count("a"), s.count("b"), s.count("c")]
a.sort(reverse=True)
print(a)
if a[0] <= a[2] + 1:
    print("YES")
else:
    print("NO")
