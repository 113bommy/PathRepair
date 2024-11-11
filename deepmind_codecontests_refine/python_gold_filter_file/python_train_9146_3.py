ans = []
for word in input().split():
    if "apple" in word:
        ans.append(word.replace("apple", "peach"))
    elif "peach" in word:
        ans.append(word.replace("peach", "apple"))
    else:
        ans.append(word)
print(*ans)