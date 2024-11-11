n = int(input())
s = input()
num = [len(set(s[:i]) & set(s[i:])for i in range(n))]
print(max(num))
