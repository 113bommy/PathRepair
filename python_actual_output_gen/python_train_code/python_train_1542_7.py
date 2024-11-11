# link: https://codeforces.com/contest/725/problem/B

def solve(seat):
    rowSeat = {
        'f': 1,
        'e': 2,
        'd': 3,
        'a': 4,
        'b': 5,
        'c': 6
    }

    seatString = seat[-1]

    row = int(seat[:-1])

    seat_seconds = rowSeat[seatString]

    time = ((row-1) // 4)*16 + ((row-1) // 2)*7+seat_seconds

    return time


if __name__ == "__main__":
    seat = input()
    ans = solve(seat)
    print(ans)
