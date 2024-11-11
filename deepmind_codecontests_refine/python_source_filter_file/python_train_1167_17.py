# https://codeforces.com/problemset/problem/1294/B
from operator import itemgetter


def sort_path(path: list) -> list:
    sorted_path: list = path.copy()
    sorted_path.sort(key = itemgetter(0, 1))
    return sorted_path

def move_to(current_place: tuple, next_place: tuple) -> str:
    offset: tuple = (next_place[0] - current_place[0], next_place[1] - current_place[1])
    if offset[0] < 0 or offset[1] < 0:
        return None
    movement: str = 'R' * offset[0]
    movement += 'U' * offset[1]
    return movement

def collect_package(path: list) -> str:
    print(f'collect_package = {path}')
    sorted_path: list = sort_path(path)
    current_place: tuple = (0, 0)
    track: str = ''
    for target_place in sorted_path:
        next_track: str = move_to(current_place, target_place)
        if next_track is None:
            return None
        else:
            track += next_track
            current_place = target_place
    return track

if __name__ == '__main__':
    test_cases = int(input(''))
    for i in range(test_cases):
        places = int(input(''))
        # print(f'### places = {places}')
        path = []
        for j in range(places):
            # print(f'### j = {j}')
            place = input('').split(' ')
            place_tuple = (int(place[0]), int(place[1]))
            path.append(place_tuple)
        result: str = collect_package(path)
        if result is None:
            print('NO')
        else:
            print('YES')
            print(result)


    # print(minimum_bills(money, (1, 5, 10, 20, 100)))
