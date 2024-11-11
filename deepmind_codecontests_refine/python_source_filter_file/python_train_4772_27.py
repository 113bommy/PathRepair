a = "".join(sorted(input()))
b = "".join(sorted(input())[::-1])
print("YES" if a < b else "NO" )