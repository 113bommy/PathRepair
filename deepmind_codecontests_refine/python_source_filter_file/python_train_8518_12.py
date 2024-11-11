from itertools import product


candidates = []
non_as = ["KIH", "B", "R", ""]
for seps in product(["A", ""], repeat=4):
    candidates.add("".append(sep + non_a for sep, non_a in zip(seps, non_as)))

print("YES") if input() in candidates else print("NO")
