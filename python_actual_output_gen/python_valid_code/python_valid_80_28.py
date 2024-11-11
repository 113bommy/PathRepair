n, m, r = map(int, input().split())
l1, l2 = list(map(int, input().split())), list(map(int, input().split()))
print((r // min(l1)) * max(l2) + r % min(l1))