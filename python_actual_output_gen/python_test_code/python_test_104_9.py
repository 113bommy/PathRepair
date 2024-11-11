A = []
for i in range(int(input())):
    a, b = list(map(int, input().split()))
    A.append(a)
    if a != b:
        print("rated")
        quit()
B = A.sort()
A.reverse()
if A == B:
    print("maybe")
else:
    print("unrated")