# # RED CODER # #
n, m = map(int, input().split())
new = []
for items in range(n):
    a, b = map(int, input().split())
    new.append((m//b)*a)
print(min(new))