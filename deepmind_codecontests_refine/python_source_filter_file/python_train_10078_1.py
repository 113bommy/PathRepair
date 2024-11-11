N = int(input())
A = list(map(int,input().split()))
B = list(map(abs,a))
C = [a for a in A if a < 0]

if len(C) % 2 == 0:
    print((sum(B)))
else:
    print((sum(B)-min(B)*2))