n = int(input())
print(len(set(map(lambda x: "".join(set(x)), input().split()))))