import sys
from collections import defaultdict


def primeSieve(n):

    """1 is not prime"""
    cache = defaultdict(list)
    cache[2].append(2)
    primes = [2]

    for i in range(2, n):
        if i in cache:
            for ele in cache[i]:
                cache[i + ele].append(ele)
            del cache[i]
        else:
            primes.append(i)
            cache[i + i].append(i)

    return primes


def solve(n):
    questions = 0
    questionList = []
    primes = primeSieve(n)

    for prime in primes:
        power = 1
        k = prime ** power
        while k <= n:
            questionList.append(k)
            power += 1
            k = prime ** power

    questions = len(questionList)

    return questions, questionList


def readinput():
    k = int(input())
    ans, lst = solve(k)
    print(ans)
    for i in range(len(lst)):
        if i != len(lst) - 1:
            print(lst[i], end=" ")
        else:
            print(lst[i], end="\n")


readinput()
