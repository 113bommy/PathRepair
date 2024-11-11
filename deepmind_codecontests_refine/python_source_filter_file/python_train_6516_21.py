length = int(input())

s = "aabbaa"

result = (s * (length//3+1))[:length]
print(result)
