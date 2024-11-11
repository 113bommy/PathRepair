N = int(input())
S = input()
print(max(len(set[:i]&set[i:])) for i in range(N))