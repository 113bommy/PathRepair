a,b = map(int,input().split())
s = input()
print('Yes') if "-" not in s[:a] and "-" not in s[-b:] and "-" in s else print('No')