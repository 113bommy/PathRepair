import math
import os
import random
import re
import sys
from operator import itemgetter, attrgetter

def _convert_status(status: str):
    status.lower()
    if status == "rat":
        return 0
    if status in ("woman", "child"):
        return 1
    if status == "man":
        return 2
    return 3

if __name__ == '__main__':
    n = int(input())
    res = list()

    for _ in range(n):
        name, status = input().strip().split()
        res.append((name, _convert_status(status)))
    res.sort(key=itemgetter(1, 0))

    for _ in res:
        print(_[0])
    