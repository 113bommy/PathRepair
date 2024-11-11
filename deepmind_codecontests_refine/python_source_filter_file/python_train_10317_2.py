
from collections import deque
from typing import Counter


def solution(word, k):
    counter = Counter(word)
    i, count = 0, 0
    least_common = counter.most_common()[::-1]

    if k > len(word):
        return "", 0

    for i, (_, n) in enumerate(least_common):
        count += n
        if count > k:
            break

    result_letters = set()
    result_count = 0
    for char, n in least_common[i:]:
        result_letters.add(char)
        result_count += 1

    return "".join([c for c in word if c in result_letters]), result_count


if __name__ == "__main__":
    word = input()
    k = int(input())

    result, result_count = solution(word, k)

    print(result_count)
    print(result)