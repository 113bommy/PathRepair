n = int(input()) 
s = "aabb"
print(s * (n // 4) + s[:n % 4])