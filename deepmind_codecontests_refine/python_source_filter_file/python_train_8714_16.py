""""the Power Gem of purple color,
the Time Gem of green color,
the Space Gem of blue color,
the Soul Gem of orange color,
the Reality Gem of red color,
the Mind Gem of yellow color.
"""
col = ["p", "g", "b,", "o", "r", "y"]
gem = ["Power", "Time", "Space", "Soul", "Reality", "Mind"]

cases = int(input())
x = cases
lst = []
while cases:
    cases -= 1
    s = input()
    lst.append(s[0])
print(6-x)
for let in col:
    if let not in lst:
        print(gem[col.index(let)])
