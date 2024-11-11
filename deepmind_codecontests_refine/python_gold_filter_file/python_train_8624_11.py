N = int(input())
s = input()
animals = ['SS', 'SW', 'WS', 'WW']
for i, animal in enumerate(animals):
  for j in range(N):
    a = 1 if animals[i][-1] == 'S' else -1
    b = 1 if animals[i][-2] == 'S' else -1
    c = 1 if s[(j + 1) % N] == 'o' else -1
    animals[i] += 'S' if a * b * c > 0 else 'W'
ans = -1
for animal in animals:
  if animal[:2] == animal[-2:]:
    ans = animal[:N]
print(ans)