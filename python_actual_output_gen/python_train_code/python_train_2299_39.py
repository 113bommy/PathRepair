N = int(input())
AL = list(map(int, input().split()))

s = "APPROVED"
for i in AL:
  if i%2 == 0 and i%3 != 0 and i%5 != 0:
    s = DENIED
print(s)