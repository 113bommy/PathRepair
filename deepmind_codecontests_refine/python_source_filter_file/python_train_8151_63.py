n, k, l, c, d, p, nl, np = map(int, input().split())

milliliters_friends_have = k*l
num_of_toasts = int(milliliters_friends_have/n)
limes_are_enough_for_toasts = c*d
salt_are_enough_for_toasts = int(p/np)
ans = min(num_of_toasts, limes_are_enough_for_toasts, salt_are_enough_for_toasts)/n

print(int(ans))