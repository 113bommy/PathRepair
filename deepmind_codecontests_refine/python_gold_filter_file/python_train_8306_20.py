#!/usr/bin/env python
# -*- coding: utf-8 -*-
import collections


class Node(object):

  def __init__(self):
    self.edges = set()
    self.distance = 1


def main():
  N = int(input())
  nodes = [Node() for _ in range(N)]

  if N == 0:
    print('Second', flush=True)
    return
  elif N == 1:
    print('First', flush=True)
    return

  for _ in range(N - 1):
    a, b = map(int, input().split())
    nodes[a - 1].edges.add(nodes[b - 1])
    nodes[b - 1].edges.add(nodes[a - 1])

  leaves = collections.deque(n for n in nodes if len(n.edges) == 1)

  while True:
    leaf = leaves.popleft()
    parent = leaf.edges.pop()

    if len(parent.edges) == 1:
      size = leaf.distance + parent.distance
      break

    parent.distance = max(parent.distance, leaf.distance + 1)
    parent.edges.remove(leaf)

    if len(parent.edges) == 1:
      leaves.append(parent)

  if size % 3 == 2:
    print('Second', flush=True)
  else:
    print('First', flush=True)


if __name__ == '__main__':
  main()

