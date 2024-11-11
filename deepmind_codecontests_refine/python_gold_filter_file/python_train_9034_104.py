s = list(input())
t = list(input())
print(sum(s[i] == t[i] for i in range(3)))