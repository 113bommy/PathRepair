S =input()
re = int(input())

if len(S) < re:
    print("impossible")
else:
    print(max(0, re - len(set(list(S)))))