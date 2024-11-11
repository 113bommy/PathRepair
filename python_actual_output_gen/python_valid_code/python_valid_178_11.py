def f(s):
    xs = [False] * 26
    s = s.lower()
    for c in s:
        i = ord(c) - ord('a')
        xs[i] = True
    if all(xs):
        return "YES"
    return "NO"

# print(f("TheQuickBrownFoxJumpsOverTheLazyDog"))
# print(f("toosmallword"))

input()
f(input())
