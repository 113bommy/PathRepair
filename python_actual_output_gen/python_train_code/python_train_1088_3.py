N = input()
for i in range(int(N)):
    a = (input())
    if len(set(a)) == 1:
        print(-1)
    else:
        print("-".join(sorted(a)))