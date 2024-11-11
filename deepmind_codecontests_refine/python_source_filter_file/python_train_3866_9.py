from typing import *


def main():
  n = int(input())
  s = input().strip()
  ans = solve(n, s)
  print(ans)


def solve(n: int, s: str) -> int:
  if n % 2 == 1:
    return 0
  if s[0] == ')' and s[-1] == '(':
    return 0
  num_closing = s.count(')')
  num_opening = s.count('(')

  if abs(num_closing-num_opening) != 2:
    return 0
  if num_closing < num_opening:
    return solve_switch_opening(n, s)
  else:
    return solve_switch_closing(n, s)


def transform(s: str) -> List[int]:
  acc, transformed = 0, []
  for c in s:
    acc += 1 if c == '(' else -1
    transformed.append(acc)
  return transformed



def solve_switch_opening(n: int, s: str) -> int:
  s_trans = transform(s)
  if len([x for x in s_trans if x < -2]) > 0:
    return 0
  switchable_min_idx = n
  for i in range(n-1, -1, -1):
    si = s_trans[i]
    if si < 2:
      break
    switchable_min_idx = i
  num_switchables = 0
  for i in range(switchable_min_idx, n):
    if s[i] == '(':
      num_switchables += 1
  return num_switchables


def solve_switch_closing(n: int, s: str) -> int:
  s_trans = transform(s)
  if len([x for x in s_trans if x < -2]) > 0:
    return 0
  switchable_max_idx = -1
  for i in range(n):
    si = s_trans[i]
    switchable_max_idx = i
    if si < 0:
      break
  num_switchables = 0
  for i in range(0, switchable_max_idx+1):
    if s[i] == ')':
      num_switchables += 1
  return num_switchables


main()
