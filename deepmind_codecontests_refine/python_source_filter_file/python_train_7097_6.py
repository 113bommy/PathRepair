def negatives(arr):
    return (len([i for i in arr if i < 0]))

def zeros(arr):
    return (len([i for i in arr if i == 0]))

def moves_to_make_one(arr):
    return sum([abs(i - 1) for i in arr])

def minimumMoves(all_moves, negatives, zeros):
    if negatives % 2 != 0:
        if zeros % 2 != 0:
            return all_moves - (2 * negatives) 
        return all_moves - (2 * negatives) + 2

    return all_moves - (2 * negatives)

size = int(input())
arr = list(map(int, input().split()))

print(minimumMoves(moves_to_make_one(arr) , negatives(arr), zeros(arr)))