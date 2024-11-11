n, k, l, c, d, p, nl, np = input().split()
n, k, l, c, d, p, nl, np = [int(n), int(k), int(l), int(c), int(d), int(p), int(nl), int(np)]

v = k*l
t = v/nl
lime = c*d
salt = p/np

toasts = min(t, lime, salt)/n
print(int(toasts))
