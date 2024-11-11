a, b = map(int, input().split())
c = input()
print(c[b-1:]+str.lower(c[b-1])+c[:b])
