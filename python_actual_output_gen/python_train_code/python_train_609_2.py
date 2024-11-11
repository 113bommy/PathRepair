balloons = input().split(' ')
def tables(balloons):
    balloons = list(map(int,balloons))
    balloons.sort()
    if balloons[2]//2 > balloons[1] + balloons[0]:
        return balloons[1] + balloons[0]
    elif (balloons[2] + balloons[1]) % 3 + balloons[1] < 4:
        return (balloons[2]+balloons[1])//3 + ((balloons[2]+balloons[1])%3+balloons[1])//3
    else:
        return sum(balloons)//3
print(tables(balloons))