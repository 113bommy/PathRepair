S=input()
K=int(input())

for i in range(K):
    if S[i]!='1':
        print(int(S[i]))
        break
else:
    print(1)