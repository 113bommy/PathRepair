N = int(input())
words = []
for _ in range(N):
    words.append(input())
print('Yes' if all(w[i].startswith(w[i-1][-1]) for i in range(1, N)) and len(set(words)) == N else 'No')