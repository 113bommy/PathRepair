instructions = ['H', 'Q', '9', '+']
string = list(input().strip())
result = 0
for m in instructions:
    if m in string:
        result = 1
if result == 1:
    print("YES")
else:
    print("NO")
