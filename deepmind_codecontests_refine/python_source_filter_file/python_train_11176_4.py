def get_type(a, b, c):
    if a == 0 and b == 0 and c == 0:
        return "all points"
    elif a == 0 and b == 0 and c != 0:
        return "no points"
    return "a line"


def solver(a_1, b_1, c_1, a_2, b_2, c_2):
    # this solver assumes that get_type
    # returns "a line" for both equations
    if b_1 == 0 and b_2 == 0:
        # compare c_1 / a_1 and c_2 / a_2
        # Note: we do not want to do direct
        # float comparison, so instead we
        # compare c_1 * a_2 and c_2 * a_1
        return -1 if c_1 * a_2 == c_2 * a_1 else 0
    elif b_1 == 0 and b_2 != 0:
        return 1
    elif b_1 != 0 and b_2 == 0:
        return 1
    else:
        # both b_1 and b_2 are not zeros
        if a_1 * b_2 == a_2 * b_1:
            # same slope, so the lines are the same if 
            # they have the same intercept; otherwise 
            # the lines are parallel
            return -1 if c_1 * b_2 == c_2 * b_1 else 0
        else:
            # different slope, so 1 intersection
            return 1

a_1, b_1, c_1 = map(int, input().split())
a_2, b_2, c_2 = map(int, input().split())

type_1 = get_type(a_1, b_1, c_1)
type_2 = get_type(a_2, b_2, c_2)

if type_1 == "no points" or type_2 == "no points":
    # obviously there is no intersection
    print(0)
elif type_1 == "all points" or type_2 == "all_points":
    # infinite intersections
    print(-1)
else:
    # both are lines
    print(solver(a_1, b_1, c_1, a_2, b_2, c_2))