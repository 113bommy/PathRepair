if __name__ == "__main__":

    x, y = input().split()
    n = int(input())

    dirs = {'^': 1, '>': 2, 'v': 3, '<': 4}

    if n%4 == 2: print('undefined')
    elif (dirs[y]-dirs[x])%4 == n%4: print('cw')
    else: print('ccw') 