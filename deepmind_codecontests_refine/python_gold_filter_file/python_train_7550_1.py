n = int(input())
mystr = input()
print(n - len(set(mystr)) if n <= 26 else -1)