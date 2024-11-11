n=int(input())
per1=input().split()
per2=input().split()
A = per1[1:]
B = per2[1:]
def func(A,B):
    if int(A[0]) > int(B[0]):
        A.append(B.pop(0))
        A.append(A.pop(0))
    else:
        B.append(A.pop(0))
        B.append(B.pop(0))
answer = 0
s=1
vse = set()
lenny = 0
while A and B:
    vse.add(''.join(A) + ''.join(B))

    func(A,B)

    if len(vse) == answer:
        s = 0
        break
    answer += 1
print(((str(answer) + ' ' + str(2 if len(A) == 0 else 1))) if s == 1 else -1)
