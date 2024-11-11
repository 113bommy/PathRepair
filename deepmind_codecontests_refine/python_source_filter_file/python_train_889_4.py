n, m = (int(x) for x in input().split())
flowers = [int(x) for x in input().split()]
final_mood = 0
for i in range(m):
    l, r = (int(x) - 1 for x in input().split())
    mood = sum(flowers[l:r])
    if mood > 0:
        final_mood += mood
print(final_mood)
