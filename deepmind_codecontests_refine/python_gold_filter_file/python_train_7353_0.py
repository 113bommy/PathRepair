n = int(input())
a = [0] * 100001
for x in map(int, input().split()):
  a[x] += 1
print('Conan' if 1 in map(lambda x: x%2, a)else 'Agasa')
