A = input()
char = [0 for _ in range(26)]

for i in range(len(A)):
    char[ord(A[i])-96] += 1

ans = 1

for i in range(25):
    for j in range(i+1,26):
        ans += char[i]*char[j]

print(ans)