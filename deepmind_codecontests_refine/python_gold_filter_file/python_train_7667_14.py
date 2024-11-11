n = int(input())
print(len(set(map(lambda x: "".join(sorted(set(x))), input().split()))))