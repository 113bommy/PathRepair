#!/usr/bin/env python
# -*- coding: utf-8 -*-
import bisect
import collections


class VBoarder(object):

  def __init__(self, x1, x2, y):
    self.x1 = x1
    self.x2 = x2
    self.y = y


class HBoarder(object):

  def __init__(self, x, y1, y2):
    self.x = x
    self.y1 = y1
    self.y2 = y2


class Cell(object):

  def __init__(self, x1, y1, x2, y2):
    self.x1 = x1
    self.y1 = y1
    self.x2 = x2
    self.y2 = y2
    self.up = True
    self.down = True
    self.left = True
    self.right = True
    self.checked = False

  def area(self):
    return (self.x2 - self.x1) * (self.y2 - self.y1)

  def __str__(self):
    return '(({:2d},{:2d}),({:2d},{:2d})){}{}{}{}'.format(
      self.x1, self.y1, self.x2, self.y2,
      'Uu'[int(self.up)], 'Dd'[int(self.down)], 'Ll'[int(self.left)], 'Rr'[int(self.right)])


def main():
  N, M = map(int, input().split())
  vborders = [VBoarder(*map(int, input().split())) for _ in range(N)]
  hborders = [HBoarder(*map(int, input().split())) for _ in range(M)]

  y_axis = list(set([b.y for b in vborders]))
  y_axis.sort()
  y_axis = [y_axis[0] - 1] + y_axis + [y_axis[-1] + 1]
  x_axis = list(set([b.x for b in hborders]))
  x_axis.sort()
  x_axis = [x_axis[0] - 1] + x_axis + [x_axis[-1] + 1]

  cells = [[Cell(x1, y1, x2, y2)
            for x1, x2 in zip(x_axis[:-1], x_axis[1:])]
           for y1, y2 in zip(y_axis[:-1], y_axis[1:])]

  for b in vborders:
    y_idx = bisect.bisect_left(y_axis, b.y)
    x_idx1 = bisect.bisect_left(x_axis, b.x1)
    x_idx2 = bisect.bisect_right(x_axis, b.x2) - 1

    for x_idx in range(x_idx1, x_idx2):
      cells[y_idx - 1][x_idx].down = False
      cells[y_idx][x_idx].up = False

  for b in hborders:
    x_idx = bisect.bisect_left(x_axis, b.x)
    y_idx1 = bisect.bisect_left(y_axis, b.y1)
    y_idx2 = bisect.bisect_right(y_axis, b.y2) - 1

    for y_idx in range(y_idx1, y_idx2):
      cells[y_idx][x_idx - 1].right = False
      cells[y_idx][x_idx].left = False

  queue = collections.deque()
  area = 0

  x = bisect.bisect_right(x_axis, 0.5) - 1
  y = bisect.bisect_right(y_axis, 0.2) - 1
  queue.append((x, y))

  while len(queue) != 0:
    x, y = queue.popleft()

    if x == 0 or x == len(x_axis) - 1 or y == 0 or y == len(y_axis):
      print('INF')
      return

    c = cells[y][x]

    if c.checked:
      continue

    area += c.area()
    c.checked = True

    if c.up:
      queue.append((x, y - 1))

    if c.down:
      queue.append((x, y + 1))

    if c.left:
      queue.append((x - 1, y))

    if c.right:
      queue.append((x + 1, y))

  print(area)


if __name__ == '__main__':
  main()
