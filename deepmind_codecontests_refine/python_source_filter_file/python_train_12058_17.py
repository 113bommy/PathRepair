n = int(input())
words = [input() for _ in range(n)]
print("Yes" if all([y[0] == x[-1] for x, y in zip(words, words[1:]) and len(set(words)) == n else "No")