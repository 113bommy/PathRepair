N = int(input())
S = input()

A = ord('A')

T = [chr(A + (ord(c) - A + N) % 26) for c in S]

print(T)