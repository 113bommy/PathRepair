# Problem
def find_isosceles_side_length(coordinates):
    largest_triangle = 0
    chosen_x = 0
    chosen_y = 0
    for coordinate in coordinates:
        x = coordinate["x"]
        y = coordinate["y"]
        hypotenuse = x + y
        if (hypotenuse > largest_triangle):
            largest_triangle = hypotenuse
            chosen_x, chosen_y = x, y

    return chosen_x + chosen_y


# Read input
if __name__ == "__main__":
    triangles = int(input())
    coordinates = []
    for i in range(0, triangles):
        line = input().split()
        x, y = (int(x) for x in line)
        coordinates.append({"x": x, "y": y})
    print(find_isosceles_side_length(coordinates))
