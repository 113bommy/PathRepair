lengths = sorted(list(map(int, input().strip().split())))

deficit = lengths[2] - (lengths[0] + lengths[1]) + 1

print(min(0, deficit))