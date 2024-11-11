def main():
  _max = max
  h, w = map(int, input().split())
  s = [input() + '#' for _ in range(h)]
  s.append('#' * (w + 1))

  rt = [[-1] * w for _ in range(h)]

  tstart = [-1] * (w + 1)
  for i in range(h + 1):
    si = s[i]
    ystart = -1
    for j in range(w + 1):
      if si[j] == '#':
        if ystart != -1:
          for k in range(ystart, j):
            rt[i][k] += j - ystart
          ystart = -1
        if tstart[j] != -1:
          for k in range(tstart[j], i):
            rt[k][j] += i - tstart[j]
          tstart[j] = -1
      else:
        if ystart == -1:
          ystart = j
        if tstart[j] == -1:
          tstart[j] = i

  print(_max(_max(l) for l in rt))

main()