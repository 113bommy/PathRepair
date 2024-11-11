n, k, l, c, d, p, nl, np = map(int, input().split())
total_toast = min( (k*l)/nl, (c*d), p/np )
print(int(total_toast/n))