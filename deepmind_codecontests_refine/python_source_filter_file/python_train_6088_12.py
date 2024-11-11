from typing import List


def solve(n: int, repost_chain: List[List[str]]) -> int:
    graph = {'polycarp': 1}
    max_height = 0
    for repost in repost_chain:
        reposter, op = repost[0], repost[-1]
        height = graph[op.lower()] + 1
        graph[reposter.lower()] = height
        max_height = max(height, max_height)
    return height

n = int(input())
repost_chain = [input().split() for _ in range(n)]

print(solve(n, repost_chain))
