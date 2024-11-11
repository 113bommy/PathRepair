input()
a = map(int, input().split())
count = 0
while all(i%2 == 0 for i in a):
  a = [i//2 for i in a]
  count += 1
print(count)
