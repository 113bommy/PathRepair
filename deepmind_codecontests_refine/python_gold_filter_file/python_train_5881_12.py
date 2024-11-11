def main(no_of_disk, original_state, scrooge_pattern):
    moves = 0
    for i in range(no_of_disk):
        moves += min(abs(original_state[i] - scrooge_pattern[i]), 10 - abs(original_state[i] - scrooge_pattern[i]))
    print(moves)


if __name__ == '__main__':
    no_of_disk = int(input())
    original_state = list(map(int, (input().replace("", " ")).split()))
    scrooge_pattern = list(map(int, (input().replace("", " ")).split()))
    main(no_of_disk, original_state, scrooge_pattern)
