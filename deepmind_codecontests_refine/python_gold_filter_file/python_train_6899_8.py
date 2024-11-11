S = input()
n = len(S)
print(3)
print("L", 2)
n += 1
S = S[1] + S
# print(S)
print("R", 2)
S = S + S[1:n-1][::-1]
n = n*2 - 2
# print(S)
print("R", n-1)
# S = S + S[n-2:n-1][::-1]

# print(S)
