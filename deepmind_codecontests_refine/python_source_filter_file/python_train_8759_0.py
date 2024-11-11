input()
s = input()
best = 10**9
for i in range(len(s) - 4 + 1):
    A = min(abs(ord(s[i]) - ord("A")),25 - abs(ord(s[i]) - ord("A")) + 1)
    B = min(abs(ord(s[i+1]) - ord("C")),25 - abs(ord(s[i+1]) - ord("C") + 1))
    C = min(abs(ord(s[i+2]) - ord("T")),25 - abs(ord(s[i+2]) - ord("T") + 1))
    D = min(abs(ord(s[i+3]) - ord("G")),25 - abs(ord(s[i+3]) - ord("G") + 1))

    current_best = A + B +C +D
    best = min(best, current_best)
print(best)