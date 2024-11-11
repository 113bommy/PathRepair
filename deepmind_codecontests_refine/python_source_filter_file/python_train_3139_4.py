def main():
  H, n = map(int, input().split(" "))
  d = [int(x) for x in input().split(" ")]

  acc_ds = list(d)
  for i in range(1, n):
    acc_ds[i] += acc_ds[i-1]
  acc_ds = [-x for x in acc_ds]
  M = max(acc_ds)
  L = acc_ds[-1]

  if M >= H:
    for i, acc_d in enumerate(acc_ds):
      if acc_d >= H:
        print(i+1)
        return

  if L == 0:
    print(-1)
    return

  max_possible_reps = H//L + 1
  min_possible_reps = H//M - 1

  reps = binary_search(H, L, M, min_possible_reps, max_possible_reps)

  hp_after_reps = H - reps*L
  for i, acc_d in enumerate(acc_ds):
    if acc_d >= hp_after_reps:
      print(reps*n + i + 1)
      return

  print((reps+1)*n)

def binary_search(H, L, M, lo, hi):
    while lo < hi:
        mi = (lo+hi) // 2
        if mi*L + M >= H:
            hi = mi
        else:
            lo = mi + 1
    return lo
main()