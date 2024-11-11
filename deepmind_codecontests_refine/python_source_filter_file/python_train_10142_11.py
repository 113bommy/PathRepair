def main():
    f = input().split()
    a = int(f[0])
    b = int(f[1])

    a_wins = 0
    b_wins = 0
    draw = 0

    for x in range(1, 7):
        if abs(a - x) > abs(b - x):
            a_wins += 1
        elif abs(a - x) < abs(b - x):
            b_wins += 1
        else:
            draw += 1

    print(a_wins, draw, b_wins)
    
if __name__ == "__main__":
    main()
