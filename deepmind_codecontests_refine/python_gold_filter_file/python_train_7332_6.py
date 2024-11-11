import sys
import math

def dist2origin(x, y):
    return x**2 + y**2

def megacity(n, s, locations):
    population = s
    distances = []
    for loc in locations:
        distances.append(math.sqrt(loc[0]**2 + loc[1]**2))
        population += loc[2]
    if population < 1000000:
        return -1
    else:
        inds = sorted(range(n), key=lambda k: distances[k])
        min_radius = 0.0
        population = s
        ind = 0
        while population < 1000000:
            min_radius = distances[inds[ind]]
            population += locations[inds[ind]][2]
            ind += 1
        return min_radius

if __name__ == '__main__':
    for line in sys.stdin:
        n_s = [int(val) for val in line.split()]
        n, s = n_s[0], n_s[1]
        locations = []
        for i in range(n):
            location = [int(val) for val in sys.stdin.readline().split()]
            locations.append(location)
        answer = megacity(n, s, locations)
        print(answer)
