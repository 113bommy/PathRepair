n = int(input())
st = input()
count = 0
for i in range(n-1):
    if st[i] == st[i+1]:
        count += 1
print(count)
