input()
heights = list(map(int, input().split()))
sortedHeights = sorted(heights)

for i,item in enumerate(sortedHeights):
    index = heights[i:].index(item) + i
    if index > i:
        for current in range(index - i):
            c = index - current - 1
            heights[c+ 1],heights[c] = heights[c],heights[c+1]
            print(c +1, c + 2)

