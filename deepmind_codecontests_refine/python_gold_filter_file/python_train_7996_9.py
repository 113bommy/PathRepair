S = input()
K = int(input())
for i in range(K):
    if S[i] != "1":
        print(S[i])
        exit()
print("1")