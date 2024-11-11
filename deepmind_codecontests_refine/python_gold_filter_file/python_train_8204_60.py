n = int(input())
s = input()
print(max([len(set(s[:x])&set(s[x:])) for x in range(1,n)]))
