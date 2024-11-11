test_cases = int(input())

for i in range(test_cases) :
    r , l , steps = map(int , input().split(" "))
    halfSteps = steps / 2
    moves = (halfSteps * r) - (halfSteps * l)
    if steps % 2 == 0 :
        print(moves)
    else :
        print(moves + r)
