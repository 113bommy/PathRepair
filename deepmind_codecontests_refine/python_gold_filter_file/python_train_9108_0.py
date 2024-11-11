#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin
from collections import defaultdict
from operator import itemgetter

def main():
  print("{}".format(run()))

def run():
  n = int(stdin.readline())
  if n == 1:
    return -1
  else:
    points = [list(map(int, stdin.readline().split())) for _ in range(n)]
    for p1 in points:
      for p2 in points:
        if p1 == p2:
          continue
        if p1[0] == p2[0] or p1[1] == p2[1]:
          continue
        return abs(p1[0] - p2[0]) * abs(p1[1] - p2[1])
    return -1

if __name__=="__main__":
   main()
