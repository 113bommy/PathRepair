N = int(input())
A = list(map(int, input().split()))
A.sort(reverse = True)
print(A)
S = set(A)
r1 = []
r1.append(A.pop())
r2 = []
cnt = 1
C = []
while A:
    tmp = A.pop()
    if tmp != r1[-1]:
        r1.append(tmp)
    else:
        if len(r2) == 0:
            r2.append(tmp)
        else:
            if tmp != r2[-1]:
                r2.append(tmp)
            else:
                C.append(tmp)
r2 = r2[::-1]
#print(r1)
#print(r2)
#print(C)

if C:
    print("NO")
else:
    if N == len(r1):
        print("YES")
        print(len(r1))
        print(" ".join(map(str, r1)))
        print(0)
        print()
    else:
        print("YES")
        print(len(r1))
        print(" ".join(map(str, r1)))
        print(len(r2))
        print(" ".join(map(str, r2)))
