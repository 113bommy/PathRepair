N = int(input())
state = [list("."*N) for _ in range(N)]

def fill_block3_1(h, w):
    state[h][w] = "a"
    state[h][w+1] = "a"
    state[h+1][w+2] = "b"
    state[h+2][w+2] = "b"

def fill_block3_2(h, w):
    state[h][w] = "c"
    state[h+1][w] = "c"
    state[h][w+1] = "d"
    state[h][w+2] = "d"
    state[h+2][w] = "e"
    state[h+2][w+1] = "e"
    state[h+1][w+2] = "f"
    state[h+2][w+2] = "f"


def solve_5_6n(start_h, start_w, k, s1, s2):
    cycle = 2*k+1
    size = 3*cycle+2
    num_2 = k
    for h3 in range(cycle):
        for w3 in range(cycle):
            if (h3+w3)%cycle < num_2:
                fill_block3_2(start_h+3*h3+1, start_w+3*w3+1)
            else:
                fill_block3_1(start_h+3*h3+1, start_w+3*w3+1)
    
    for x in range(size-1):
        if x%4 in [0, 1]:
            state[start_h][start_w+x] = s1
            state[start_h+size-2-x][start_w+size-1] = s2
            state[start_h+size-1][start_w+size-1-x] = s1
            state[start_h+1+x][start_w] = s2
        else:
            state[start_h][start_w+x] = s2
            state[start_h+size-2-x][start_w+size-1] = s1
            state[start_h+size-1][start_w+size-1-x] = s2
            state[start_h+1+x][start_w] = s1


def solve_2_6n(start_h, start_w, k, s1, s2):
    cycle = 2*k
    size = 3*cycle+2
    num_2 = k-2
    if k == 1:
        fill_block3_1(start_h+1, start_w+1)
        fill_block3_1(start_h+4, start_w+4)
    else:
        for h3 in range(cycle):
            for w3 in range(cycle):
                if (h3+w3)%cycle < num_2:
                    fill_block3_2(start_h+3*h3+1, start_w+3*w3+1)
                else:
                    fill_block3_1(start_h+3*h3+1, start_w+3*w3+1)
    for x in range(1, size-1):
        if x%4 in [1, 2]:
            state[start_h][start_w+x] = s1
            state[start_h+x][start_w] = s1
            state[start_h+size-1][start_w+x] = s1
            state[start_h+x][start_w+size-1] = s1
        else:
            state[start_h][start_w+x] = s2
            state[start_h+x][start_w] = s2
            state[start_h+size-1][start_w+x] = s2
            state[start_h+x][start_w+size-1] = s2


def solve_1_6n(start_h, start_w, k, s1, s2):
    cycle = 2*k
    size = 3*cycle+1
    for h3 in range(cycle):
        for w3 in range(cycle):
            if (h3+w3)%cycle < k-1:
                fill_block3_2(start_h+3*h3+1, start_w+3*w3+1)
            else:
                fill_block3_1(start_h+3*h3+1, start_w+3*w3+1)
    for x in range(1, size):
        if x%4 in [0, 1]:
            state[start_h][start_w+x] = s1
            state[start_h+x][start_w] = s1
        else:
            state[start_h][start_w+x] = s2
            state[start_h+x][start_w] = s2


def main():
    if N == 2:
        return -1
    if N == 4:
        state = [
            ["a", "a", "c", "d"],
            ["b", "b", "c", "d"],
            ["e", "f", "g", "g"],
            ["e", "f", "h", "h"]
        ]
        return state
    if N%3 == 0:
        l = N//3
        for h in range(l):
            for w in range(l):
                fill_block3_1(3*h, 3*w)
        return
    elif N%6 == 5:
        k = (N-5)//6
        solve_5_6n(0, 0, k, "x", "y")
        return
    elif N%6 == 2:
        k = (N-2)//6
        solve_2_6n(0, 0, k, "x", "y")
        return
    elif N%6 == 1:
        solve_1_6n(0, 0, (N-1)//6, "x", "y")
        return
    else:
        l = (N//2-2)//3
        if l%2 == 1:
            solve_5_6n(0, 0, (l-1)//2, "s", "t")
            solve_5_6n(N//2, 0, (l-1)//2, "u", "v")
            solve_5_6n(0, N//2, (l-1)//2, "w", "x")
            solve_5_6n(N//2, N//2, (l-1)//2, "y", "z")
        else:
            solve_2_6n(0, 0, l//2, "s", "t")
            solve_2_6n(N//2, 0, l//2, "u", "v")
            solve_2_6n(0, N//2, l//2, "w", "x")
            solve_2_6n(N//2, N//2, l//2, "y", "z")
        return


if __name__ == "__main__":
    ret = main()
    if ret == -1:
        print(-1)
    elif not ret is None:
        for h in range(N):
            print("".join(ret[h]))
    else:
        for h in range(N):
            print("".join(state[h]))