import sys
F = sys.stdin.readline().strip()
M = sys.stdin.readline().strip()
P = sys.stdin.readline().strip()

for i in range (0, 3):
    x = ["rock", "paper", "scissors"]
    if F == x[i]:
        F = i      
    if M == x[i]:
        M = i      
    if P == x[i]:
        P = i      
if (F+M+P) % 3 != 1:
    print("?")
else:
    if (F - M + 3) % 3 == 1:
        print("F")
    if (M - P + 3) % 3 == 1:
        print("M")
    if (P - F + 3) % 3 == 1:
        print("P")