n, k, t = input().split()
if int(t) < int(k):
    print(int(t))
elif int(k) < int(t) < int(n):
    print(int(k))
else:
    print(int(n) + int(k) - int(t))