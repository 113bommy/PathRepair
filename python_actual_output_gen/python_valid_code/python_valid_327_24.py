import sys

awake = 0

for floor in sys.stdin.readlines()[1:]:
    for flat in zip(*[iter(floor[:-1].split())]*2):
        awake += sum(map(int, flat))

print(awake)