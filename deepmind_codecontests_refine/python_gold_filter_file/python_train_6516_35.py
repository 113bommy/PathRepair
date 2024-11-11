length = int(input())

s = "aabbaabb"

result = (s * (length//3+1))[:length]
print(result)
