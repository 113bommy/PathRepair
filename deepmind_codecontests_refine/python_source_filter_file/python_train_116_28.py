n = int(input())
S = input()

last = 0
for i in range(1, n):
    if S[i] < S[last]:
        print("YES")
        print(last, i)
        break
    last = i
else:
    print("NO")