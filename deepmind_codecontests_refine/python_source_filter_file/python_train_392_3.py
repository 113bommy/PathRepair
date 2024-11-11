n=int(input())
A=[int(input()) for i in range(n)]
B=sorted(A)
for a in A:
    if a == B[-1]:
      print(B[-1])
    else:
        print(B[-2])