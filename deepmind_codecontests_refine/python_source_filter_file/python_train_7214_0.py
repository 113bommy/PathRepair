from collections import deque
from typing import List, Optional


class ContestParser:
    """Helper module to read/write

    Commonly in programming competition input for a problem is given with space separated numbers and strings.
    Standard python input() functionality is clunky when dealing with such input. This parser can tokenize inputs and convert them to proper types.
    """

    def __init__(self):
        self.buffer = deque()

    def next_token(self) -> str:
        if len(self.buffer) == 0:
            self.buffer.extend(input().split())
        return self.buffer.popleft()

    def next_int(self) -> int:
        return int(self.next_token())

    def get_int_list(self, n: int) -> List[int]:
        return [self.next_int() for i in range(n)]


def find_diffs(a1: List[int], a2: List[int]) -> List[int]:
    return [i for i, (e1, e2) in enumerate(zip(a1, a2)) if e1 != e2]


def attempt(arrays: List[List[int]], guess: List[int], changes_left: int, max_changes: int) -> Optional[List[int]]:
    for array in arrays:
        diffs = find_diffs(guess, array)
        if len(diffs) <= max_changes:
            continue
        if len(diffs) > max_changes + changes_left:
            return None
        for d in diffs:
            new_guess = guess
            new_guess[d] = array[d]
            result = attempt(arrays, new_guess, changes_left - 1, max_changes)
            if result is not None:
                return result
        return None
    return guess


if __name__ == '__main__':
    parser = ContestParser()
    n = parser.next_int()
    m = parser.next_int()
    arrays = [parser.get_int_list(m) for i in range(n)]
    result = attempt(arrays, arrays[0], 2, 2)
    if result is not None:
        print("Yes")
        print(" ".join((str(x) for x in result)))
    else:
        print("No")
