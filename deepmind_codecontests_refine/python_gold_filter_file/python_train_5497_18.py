#!/usr/bin/python3
# -*- coding: utf-8 -*-
import math

MOD = 1000000007



def fact(n):
  ans = {0}
  for i in range(1,math.ceil(n**0.5)+1):
      ans.add(i)
      ans.add(n//i)
  return sorted(list(ans))

def main():
  N,K = map(int, input().split())
  dp = [{} for _ in range(K+1)]
  keys = fact(N)
  dp[1] = {f:f for f in keys}

  for i in range(1,K):
    j_prev = 0
    dp[i+1][0] = 0
    for j in keys[1:]:
      dp[i+1][j] = (dp[i+1][j_prev] + (j-j_prev)*dp[i][N//j]) % MOD
      j_prev = j
  print(dp[K][N])


if __name__ == "__main__":
  main()