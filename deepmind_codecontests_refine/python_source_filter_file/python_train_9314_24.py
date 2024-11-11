import functools

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def absolute_slope(self, p):
        if self.x == p.x:
            return float("inf")
        
        slope = (p.y - self.y) / (p.x - self.x)
        return abs(slope)

class LazerGun:       
    def solution(self):
        first_line = input()
        first_line = first_line.split(" ")
        num_stormtroopers = int(first_line[0])
        gun = Point(int(first_line[1]), int(first_line[2]))

        stormtroopers = []
        for _ in range(num_stormtroopers):
            point = input()
            point = point.split(" ")
            stormtroopers.append(Point(int(point[0]), int(point[1])))

        abs_slopes = set()
        for stormtrooper in stormtroopers:
            abs_slope = gun.absolute_slope(stormtrooper)
            abs_slopes.add(abs_slope)
        
        min_shots = len(abs_slopes)
        print(min_shots)



if __name__ == "__main__":
    lazer_gun = LazerGun()
    lazer_gun.solution()
