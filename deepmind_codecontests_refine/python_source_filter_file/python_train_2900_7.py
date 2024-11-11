aI, aO, aT, aJ, aL, aS, aZ = map(int, input().split())

K = aO + aI // 2 * 2 + aJ // 2 * 2 + aL // 2 * 2

if aI > 0 and aJ > 0 and aL > 0:
  K = min(aO + 3 + (aI - 1) // 2 * 2 + (aJ - 1) // 2 * 2 + (aL - 1) // 2 * 2, K)

print(K)