k = int(input())
sen = input()
print(sen[:k] + ('...' if len(sen) > k else ''))
