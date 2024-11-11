n = int(input())
word = input().strip()

print(max([len(set([s for s in word[:i] if s in word[i:]])) for i in range(1, n-1)]))
