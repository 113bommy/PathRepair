def f():
    s1 = input()
    s2 = input()
    if set(s1) == set(s2):
        return "YES"
    return "NO"


for i in range(int(input())):
    print(f())
