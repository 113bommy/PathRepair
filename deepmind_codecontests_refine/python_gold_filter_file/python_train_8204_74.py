n = int(input())
s = input()
num = [len(set(s[:i])&set(s[i:])) for i in range(len(s))]
print(max(num))
