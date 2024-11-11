S =input()
re = int(input())

if len(S) < re:
    print("impossible")
else:
    print(re - len(set(list(S))))