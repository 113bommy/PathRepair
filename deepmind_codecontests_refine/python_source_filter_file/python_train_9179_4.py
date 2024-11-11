n = int(input())
word = list(input())
cnt = 0
for i in range(n//2):
    if word[i] == word[i+1]:
        cnt += 1
        word[i] = ["a", "b"][word[i] == "a"]
print(cnt)
print("".join(word))